#include "Bridge1.h"
#include<iostream>

int main()
{
	Teacher teacher1("Tom");
	Teacher teacher2("John");

	RectureBridge recture_bridge;

	recture_bridge.SetTeaher(&teacher1);

	recture_bridge.ClassStart();
	recture_bridge.TakeBreakTime();
	recture_bridge.GiveGrades();
	std::cout << '\n';

	recture_bridge.SetTeaher(&teacher2);

	recture_bridge.ClassStart();
	recture_bridge.TakeBreakTime();
	recture_bridge.GiveGrades();

	return 0;
}