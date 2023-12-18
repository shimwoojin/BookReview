#include "FactoryMethod3.h"

int main()
{
	ComputerDeviceMaker_V3<Mouse> mouse_maker;
	ComputerDeviceMaker_V3<Keyboard> keyboard_maker;
	ComputerDeviceMaker_V3<Monitor> monitor_maker;

	Mouse* mouse = mouse_maker.Create();
	Keyboard* keyboard = keyboard_maker.Create();
	Monitor* monitor = monitor_maker.Create();

	mouse->TurnOn();
	keyboard->TurnOn();
	monitor->TurnOn();

	return 0;
}