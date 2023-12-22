#include "Facade1.h"
#include <iostream>

int main()
{
	Man man;
	GoodNightMaker goodnight_maker;
	
	std::cout << "남자의 행복도 : " << man.GetHappiness() << std::endl;

	goodnight_maker.HaveAGoodNight(&man, 8, Bed::Type::soft);

	std::cout << "남자의 행복도 : " << man.GetHappiness() << std::endl;

	return 0;
}