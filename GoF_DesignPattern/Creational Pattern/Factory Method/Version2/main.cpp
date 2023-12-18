#include "FactoryMethod2.h"

int main()
{
	ComputerDeviceMaker_V2 cd_maker;

	ComputerDevice* cd1 = cd_maker.Create(DeviceType::Keyboard);
	ComputerDevice* cd2 = cd_maker.Create(DeviceType::Monitor);
	ComputerDevice* cd3 = cd_maker.Create(DeviceType::Mouse);

	cd1->TurnOn();
	cd2->TurnOn();
	cd3->TurnOn();

	return 0;
}