Dorothy!

node = with Node!
	\addChild with Model "Model/xiaoli.model"
		.y = -80
		.loop = true
		.faceRight = true
		.look = "happy"
		\play "walk"
		\runAction Sequence(
			X 2,-150,250
			Emit "Turn"
			X 2,250,-150
			Emit "Turn"
		)
		\slot "ActionEnd",(action)-> \runAction action
		\slot "Turn",-> .faceRight = not .faceRight

renderTarget = with RenderTarget 300,400
	.z = 300
	.angleY = 25
	\addChild Line {
		Vec2.zero
		Vec2 300,0
		Vec2 300,400
		Vec2 0,400
		Vec2.zero
	},Color 0xff00ffff
	\renderWithClear Color 0xff8a8a8a
	\schedule ->
		node.y = 200
		\renderWithClear node,Color 0xff8a8a8a
		node.y = 0

Director.entry\addChild with Node!
	\addChild renderTarget
	\addChild node

-- example codes ends here, some test ui below --

Dorothy builtin.ImGui

Director.entry\addChild with Node!
	\schedule ->
		{:width,:height} = App.visualSize
		SetNextWindowPos Vec2(width-250,10), "FirstUseEver"
		SetNextWindowSize Vec2(240,120), "FirstUseEver"
		if Begin "Render Target", "NoResize|NoSavedSettings"
			TextWrapped "Use render target node as a mirror!"
		End!
