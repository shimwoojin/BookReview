#include "FactoryMethod1.h"
#include <vector>

int main()
{
	std::vector<ComputerDevice*> computer_devices;

	MonitorMaker montitor_maker;
	KeyboardMaker keyboard_maker;
	MouseMaker mouse_maker;

	computer_devices.push_back(montitor_maker.Create());
	computer_devices.push_back(keyboard_maker.Create());
	computer_devices.push_back(mouse_maker.Create());

	for (ComputerDevice* cd : computer_devices)
	{
		cd->TurnOn();
	}

	return 0;
}