#include "Facade1.h"
#include <iostream>

int main()
{
	Man man;
	GoodNightMaker goodnight_maker;
	
	std::cout << "������ �ູ�� : " << man.GetHappiness() << std::endl;

	goodnight_maker.HaveAGoodNight(&man, 8, Bed::Type::soft);

	std::cout << "������ �ູ�� : " << man.GetHappiness() << std::endl;

	return 0;
}