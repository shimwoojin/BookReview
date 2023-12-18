#pragma once
#include <string>
#include <iostream>

class ComputerDevice
{
public:
	virtual void TurnOn() = 0;
};

class Mouse : public ComputerDevice
{
public:
	virtual void TurnOn()
	{
		std::cout << name << "의 전원을 켭니다" << std::endl;
	}

private:
	std::string name = "Mouse";
};

class Keyboard : public ComputerDevice
{
public:
	virtual void TurnOn()
	{
		std::cout << name << "의 전원을 켭니다" << std::endl;
	}

private:
	std::string name = "Keyboard";
};

class Monitor : public ComputerDevice
{
public:
	virtual void TurnOn()
	{
		std::cout << name << "의 전원을 켭니다" << std::endl;
	}

private:
	std::string name = "Monitor";
};