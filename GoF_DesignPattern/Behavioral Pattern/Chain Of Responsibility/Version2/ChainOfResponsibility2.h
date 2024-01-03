#pragma once

enum class EAction
{
	Fly,
	Sprint,
	Jump,
	None
};

__interface IAction
{
	void DoAction();
	EAction WhatAction();
};

class ActionMan : public IAction
{
public:
	ActionMan() {}

public:
	virtual void DoAction() override;
	virtual EAction WhatAction() override;
	void SetAction(IAction* ActionHelper);

private:
	IAction* ActionHelper = nullptr;
};

class FlyHelper : public IAction
{
public:
	virtual void DoAction() override;
	virtual EAction WhatAction() override;
};

class JumpHelper : public IAction
{
public:
	virtual void DoAction() override;
	virtual EAction WhatAction() override;
};

class SprintHelper : public IAction
{
public:
	virtual void DoAction() override;
	virtual EAction WhatAction() override;
};