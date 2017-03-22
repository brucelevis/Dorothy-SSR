local Application = builtin.Application()
local Content = builtin.Content()
local Director = builtin.Director()
local TextureCache = builtin.TextureCache()

local tolua = builtin.tolua
local yield = coroutine.yield
local wrap = coroutine.wrap
local table_insert = table.insert
local table_remove = table.remove
local type = type

builtin.Application = Application
builtin.Content = Content
builtin.Director = Director
builtin.TextureCache = TextureCache

local function wait(cond)
	repeat
		yield(false)
	until not cond(Director.deltaTime)
end

local function once(work)
	return wrap(function()
		work()
		return true
	end)
end

local function loop(work)
	return wrap(function()
		repeat yield(false) until work() == true
		return true
	end)
end

local function seconds(duration)
	local time = 0
	return function(deltaTime)
		time = time + deltaTime
		return time < duration
	end
end

local function cycle(duration,work)
	local time = 0
	local function worker()
		local deltaTime = Director.deltaTime
		time = time + deltaTime
		if time < duration then
			work(time/duration)
			return true
		else
			work(1)
			return false
		end
	end
	work(0)
	if time < duration then
		yield(false)
		while worker() do
			yield(false)
		end
	end
end

local function Routine_end() return true end
local Routine =
{
	remove = function(self,routine)
		for i = 1,#self do
			if self[i] == routine then
				self[i] = Routine_end
				return true
			end
		end
		return false
	end,
	clear = function(self)
		while #self > 0 do
			table_remove(self)
		end
	end,
}

setmetatable(Routine,
{
	__call = function(self,routine)
		table_insert(self,routine)
		return routine
	end,
})

Director.systemScheduler:schedule(function()
	local i,count = 1,#Routine
	while i <= count do
		if Routine[i]() then
			Routine[i] = Routine[count]
			table_remove(Routine,count)
			i = i-1
			count = count-1
		end
		i = i+1
	end
	return false
end)

builtin.Routine = Routine
builtin.wait = wait
builtin.once = once
builtin.loop = loop
builtin.seconds = seconds
builtin.cycle = cycle

builtin.thread = function(routine)
	return Routine(once(routine))
end

builtin.threadLoop = function(routine)
	return Routine(loop(routine))
end

builtin.sleep = function(duration)
	if duration then
		local time = 0
		repeat
			yield(false)
			time = time + Director.deltaTime
		until time >= duration
	else
		yield()
	end
end

builtin.using = function(path)
	if path then
		return function(name)
			local result = package.loaded[name]
			if not result then
				result = require(path.."."..name)
			end
			return result
		end
	else
		return require
	end
end
_G.using = builtin.using

local Content_loadAsync = Content.loadAsync
Content.loadAsync = function(self,filename,handler)
	local isloaded = false
	local loadedData
	Content_loadAsync(self,filename,function(data)
		if handler then
			handler(filename, data)
		end
		loadedData = data
		isloaded = true
	end)
	wait(function() return not isloaded end)
	return loadedData
end

local Content_copyAsync = Content.copyAsync
Content.copyAsync = function(self,src,dst)
	local loaded  = false
	Content_copyAsync(self,src,dst,function()
		loaded = true
	end)
	wait(function() return not loaded end)
end

local TextureCache_loadAsync = TextureCache.loadAsync
TextureCache.loadAsync = function(self,filename,handler)
	local isloaded = false
	local loadedTexture
	TextureCache_loadAsync(self,filename,function(texture)
		if handler then
			handler(texture)
		end
		loadedTexture = texture
		isloaded = true
	end)
	wait(function() return not isloaded end)
	return loadedTexture
end

local Action = builtin.Action
local Node = builtin.Node
local Node_runAction = Node.runAction
Node.runAction = function(self,action)
	if type(action) == "table" then
		Node_runAction(self,Action(action))
	else
		Node_runAction(self,action)
	end
end
local Node_perform = Node.perform
Node.perform = function(self,action)
	if type(action) == "table" then
		Node_perform(self,Action(action))
	else
		Node_perform(self,action)
	end
end

for _,actionName in ipairs{
	"X",
	"Y",
	"Z",
	"ScaleX",
	"ScaleY",
	"SkewX",
	"SkewY",
	"Angle",
	"AngleX",
	"AngleY",
	"Width",
	"Height",
	"AnchorX",
	"AnchorY",
	"Opacity",
	"Hide",
	"Show",
	"Delay",
	"Call",
	"Spawn",
	"Sequence",
	} do
	builtin[actionName] = function(...)
		return {actionName, ...}
	end
end

local function disallowAssignGlobal(_,name)
	error("Disallow creating global value \""..name.."\".")
end

local dorothyEnvMeta = {
	__index = builtin,
	__newindex = disallowAssignGlobal
}

-- env must be a data only table without metatable
local function Dorothy(env)
	if env then
		setfenv(2,setmetatable(env,dorothyEnvMeta))
	else
		setfenv(2,builtin)
	end
end
_G.Dorothy = Dorothy
builtin.Dorothy = Dorothy

for k,v in pairs(_G) do
	builtin[k] = v
end
setmetatable(package.loaded,{__index=builtin})

local builtinEnvMeta = {
	__newindex = disallowAssignGlobal
}
setmetatable(_G,builtinEnvMeta)
setmetatable(builtin,builtinEnvMeta)

collectgarbage("setpause", 100)
collectgarbage("setstepmul", 5000)
