#pragma once

__interface IAction
{
	void Fly();
};

class ActionMan : public IAction
{
public:
	ActionMan(IAction* FlyHelper) : FlyHelper(FlyHelper) {}

public:
	virtual void Fly() override;

private:
	IAction* FlyHelper;
};

class ActionChain : public IAction
{
public:
	virtual void Fly() override;
};