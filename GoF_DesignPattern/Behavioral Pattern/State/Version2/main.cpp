#include "State2.h"

int main()
{
	Character2* character = new Character2;

	for (int i = 0; i < 20; i++)
	{
		character->MouseLeftClick();
	}

	return 0;
}