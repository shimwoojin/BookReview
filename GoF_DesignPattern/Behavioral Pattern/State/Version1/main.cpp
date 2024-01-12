#include "State1.h"

int main()
{
	Character* character = new Character;

	for (int i = 0; i < 20; i++)
	{
		character->MouseLeftClick();
	}

	return 0;
}