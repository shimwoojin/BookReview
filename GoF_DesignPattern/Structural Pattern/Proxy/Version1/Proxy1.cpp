#include "Proxy1.h"
#include <iostream>
#include <type_traits>

void Computer::TurnOn()
{
	std::cout << "컴퓨터 전원이 켜집니다" << std::endl;
}

void Computer::TurnOff()
{
	std::cout << "컴퓨터 전원이 꺼집니다" << std::endl;
}

ComputerProxy::~ComputerProxy()
{
	if (computer)
	{
		delete computer;
	}
}

void ComputerProxy::TogglePower(Person* person)
{
	if (AccessiblePeople.find(person) == AccessiblePeople.end())
	{
		std::cout << "접근 권한이 없습니다!!" << std::endl;
		return;
	}

	if (bTurnOn)
	{
		TurnOff();
	}
	else
	{
		TurnOn();
	}
}

void ComputerProxy::TurnOn()
{
	operator->()->TurnOn();
	bTurnOn = true;
}

void ComputerProxy::TurnOff()
{
	operator->()->TurnOff();
	bTurnOn = false;
}

Device* ComputerProxy::operator->()
{
	if (computer == nullptr)
	{
		computer = new Computer;
	}

	return computer;
}
