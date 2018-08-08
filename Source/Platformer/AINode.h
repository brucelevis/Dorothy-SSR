/* Copyright (c) 2018 Jin Li, http://www.luvfight.me

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

NS_DOROTHY_PLATFORMER_BEGIN

class AILeaf;

/** @brief Behavior Tree base node */
class AILeaf : public Object
{
public:
	virtual bool doAction() = 0;
	DORA_TYPE_OVERRIDE(AILeaf);
};

class AINode : public AILeaf
{
public:
	AINode* add(AILeaf* node);
	void remove(AILeaf* node);
	void clear();
	const RefVector<AILeaf>& getChildren() const;
protected:
	RefVector<AILeaf> _children;
};

/** @brief Selector Node */
class SelNode : public AINode
{
public:
	virtual bool doAction();
	CREATE_FUNC(SelNode);
protected:
	SelNode() { }
};

/** @brief Sequence Node */
class SeqNode : public AINode
{
public:
	virtual bool doAction();
	CREATE_FUNC(SeqNode);
protected:
	SeqNode() { }
};

/** @brief Parallel Selector Node */
class ParSelNode : public AINode
{
public:
	virtual bool doAction();
	CREATE_FUNC(ParSelNode);
protected:
	ParSelNode() { }
};

/** @brief Parallel Sequence Node */
class ParSeqNode : public AINode
{
public:
	virtual bool doAction();
	CREATE_FUNC(ParSeqNode);
protected:
	ParSeqNode() { }
};

class ConNode : public AILeaf
{
public:
	virtual bool doAction();
	CREATE_FUNC(ConNode);
protected:
	ConNode(const function<bool()>& handler);
private:
	function<bool()> _handler;
};

class ActNode : public AILeaf
{
public:
	virtual bool doAction();
	CREATE_FUNC(ActNode);
protected:
	ActNode(String actionName);
private:
	string _actionName;
};

AILeaf* Sel(AILeaf* nodes[], int count);
AILeaf* Seq(AILeaf* nodes[], int count);
AILeaf* ParSel(AILeaf* nodes[], int count);
AILeaf* ParSeq(AILeaf* nodes[], int count);
AILeaf* Con(const function<bool()>& handler);
AILeaf* Act(String actionName);

NS_DOROTHY_PLATFORMER_END
