/* Copyright (c) 2013 Jin Li, http://www.luvfight.me

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

NS_DOROTHY_BEGIN

class Event;
class Listener;
class Signal;
class Slot;

typedef Delegate<void (Event* event)> EventHandler;

class Node : public Object
{
public:
	PROPERTY(int, Order);
	PROPERTY(float, Angle);
	PROPERTY(float, ScaleX);
	PROPERTY(float, ScaleY);
	PROPERTY(float, X);
	PROPERTY(float, Y);
	PROPERTY(float, Z);
	PROPERTY_VIRTUAL_REF(Vec2, Position);
	PROPERTY(float, SkewX);
	PROPERTY(float, SkewY);
	PROPERTY_BOOL(Visible);
	PROPERTY_REF(Vec2, Anchor);
	PROPERTY(float, Width);
	PROPERTY(float, Height);
	PROPERTY_REF(Size, Size);
	PROPERTY_REF(string, Name);
	PROPERTY(float, Opacity);
	PROPERTY_READONLY(float, RealOpacity);
	PROPERTY(Color, Color);
	PROPERTY(Color3, Color3);
	PROPERTY_READONLY(Color, RealColor);
	PROPERTY_BOOL(PassOpacity);
	PROPERTY_BOOL(PassColor3);
	PROPERTY(Node*, TransformTarget);
	PROPERTY(Scheduler*, Scheduler);
	PROPERTY(Object*, UserData);
	PROPERTY_READONLY(Node*, Parent);
	PROPERTY_READONLY(Node*, TargetParent);
	PROPERTY_READONLY(Array*, Children);
	PROPERTY_READONLY_BOOL(Running);
	PROPERTY_READONLY_BOOL(Updating);
	PROPERTY_READONLY_BOOL(Scheduled);

	virtual void addChild(Node* child, int order, String name);
	void addChild(Node* child, int order);
	void addChild(Node* child);

	virtual Node* addTo(Node* parent, int order, String name);
	Node* addTo(Node* parent, int order);
	Node* addTo(Node* parent);

	void removeChild(Node* child, bool cleanup = true);
	void removeChildByName(String name, bool cleanup = true);
	void removeAllChildren(bool cleanup = true);

	virtual Rect getBoundingBox();

	virtual void onEnter();
	virtual void onExit();
	virtual void cleanup();

	Node* getChildByName(String name);

	void schedule(const function<bool(double)>& func);
	void unschedule();

	Vec2 convertToNodeSpace(const Vec2& worldPoint);
	Vec2 convertToWorldSpace(const Vec2& nodePoint);

	void scheduleUpdate();
	void unscheduleUpdate();

	virtual void visit(const float* world = Matrix::Indentity);
	virtual void render(float* world);
	virtual bool update(double deltaTime) override;

	const AffineTransform& getLocalTransform();
	AffineTransform getWorldTransform();

	void getLocalWorld(float* localWorld);
	void getWorld(float* world);

	void emit(Event* event);

	template <class ...Args>
	void emit(String name, Args ...args)
	{
		if (_signal)
		{
			EventArgs<Args...> event(name, args...);
			emit(&event);
		}
	}

	Slot* slot(String name);
	Slot* slot(String name, const EventHandler& handler);
	void slot(String name, std::nullptr_t);

	Listener* gslot(String name, const EventHandler& handler);
	void gslot(String name, std::nullptr_t);
	void gslot(Listener* listener, std::nullptr_t);
	RefVector<Listener> gslot(String name);

	CREATE_FUNC(Node);
/*
	PROPERTY_READONLY(int, ActionCount);
	void runAction(CCAction* action);
	void stopAllActions();
	void perform(CCAction* action);
	void stopAction(CCAction* action);
*/
protected:
	Node();
	virtual ~Node();
	void setOn(Uint32 type);
	void setOff(Uint32 type);
	void setFlag(Uint32 type, bool value);
	void markDirty();
	bool isOn(Uint32 type) const;
	bool isOff(Uint32 type) const;
	void updateRealColor3();
	void updateRealOpacity();
	void sortAllChildren();
protected:
	Uint32 _flags;
	int _order;
	Color _color;
	Color _realColor;
	float _angle;
	float _angleX;
	float _angleY;
	float _scaleX;
	float _scaleY;
	float _skewX;
	float _skewY;
	float _positionZ;
	float* _world;
	Vec2 _position;
	Vec2 _anchor;
	Vec2 _anchorPoint;
	Size _size;
	AffineTransform _transform;
	WRef<Node> _transformTarget;
	Node* _parent;
	Ref<Object> _userData;
	Ref<Array> _children;
	Ref<Scheduler> _scheduler;
	Own<Signal> _signal;
	string _name;
	function<bool(double)> _scheduleFunc;
	enum
	{
		Visible = 1,
		TransformDirty = 1 << 1,
		Running = 1 << 2,
		Updating = 1 << 3,
		Scheduling = 1 << 4,
		PassOpacity = 1 << 5,
		PassColor3 = 1 << 6,
		Reorder = 1 << 7,
		Cleanup = 1 << 8,
		TouchEnabled = 1<<9,
		KeypadEnabled = 1<<10,
		KeyboardEnabled = 1<<11,
	};
	DORA_TYPE_OVERRIDE(Node);
};

class Slot : public Object
{
public:
	void add(const EventHandler& handler);
	void set(const EventHandler& handler);
	void remove(const EventHandler& handler);
	void clear();
	void handle(Event* event);
	CREATE_FUNC(Slot);
protected:
	Slot(const EventHandler& handler);
private:
	EventHandler _handler;
	DORA_TYPE_OVERRIDE(Slot);
};

class Signal
{
public:
	Slot* addSlot(String name, const EventHandler& handler);
	Listener* addGSlot(String name, const EventHandler& handler);
	void removeSlot(String name, const EventHandler& handler);
	void removeGSlot(Listener* gslot);
	void removeSlots(String name);
	void removeGSlots(String name);
	RefVector<Listener> getGSlots(String name) const;
	void emit(Event* event);
	static const size_t MaxSlotArraySize;
private:
	Own<unordered_map<string, Ref<Slot>>> _slots;
	Own<vector<std::pair<string, Ref<Slot>>>> _slotsArray;
	RefVector<Listener> _gslots;
};

NS_DOROTHY_END
