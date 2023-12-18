#pragma once
#include "FactoryMethod3_Components.h"
#include <type_traits>

template<typename T>
class ComputerDeviceMaker_V3
{
public:
	ComputerDeviceMaker_V3()
	{
		static_assert(std::is_base_of_v<ComputerDevice, T>, "T is not derived from ComputerDevice Class");
	}

public:
	T* Create()
	{
		return new T;
	}
};