#pragma once
#include "FactoryMethod2_Components.h"

enum class DeviceType
{
	Monitor,
	Mouse,
	Keyboard
};

class ComputerDeviceMaker_V2
{
public:
	ComputerDevice* Create(DeviceType device_type)
	{
		switch (device_type)
		{
		case DeviceType::Monitor:
			return new Monitor;
			break;
		case DeviceType::Mouse:
			return new Mouse;
			break;
		case DeviceType::Keyboard:
			return new Keyboard;
			break;
		}
	}
};