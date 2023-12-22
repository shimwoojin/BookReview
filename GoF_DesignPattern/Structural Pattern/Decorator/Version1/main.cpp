#include "Decorator1.h"
#include <iostream>

void PrintDamage(Pikachu& pikachu)
{
	std::cout << "Pikachu Damage : " << pikachu.GetDamage() << std::endl;
}

int main()
{
	Pikachu pikachu;
	PikachuDecorator_Heavy pikachu_heavy(&pikachu, 20.0f);

	PrintDamage(pikachu);
	PrintDamage(pikachu_heavy);

	return 0;
}