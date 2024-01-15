#pragma once

class TemplateMethod
{
public:
	void Activate();

protected:
	virtual void OnActivate() = 0;
};

class DerivedTemplateMethod : public TemplateMethod
{
protected:
	virtual void OnActivate();
};