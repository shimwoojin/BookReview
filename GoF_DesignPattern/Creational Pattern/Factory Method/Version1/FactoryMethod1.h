#include "FactoryMethod1_Components.h"

class ComputerDeviceMaker
{
public:
	virtual ComputerDevice* Create() = 0;
};

class MonitorMaker : public ComputerDeviceMaker
{
public:
	virtual ComputerDevice* Create()
	{
		return new Monitor;
	}
};

class MouseMaker : public ComputerDeviceMaker
{
public:
	virtual ComputerDevice* Create()
	{
		return new Mouse;
	}
};

class KeyboardMaker : public ComputerDeviceMaker
{
public:
	virtual ComputerDevice* Create()
	{
		return new Keyboard;
	}
};