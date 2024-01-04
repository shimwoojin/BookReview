#include "Iterator1.h"
#include <iostream>

int main()
{
	Inventory<int> inventory;

	for (int i = 0; i < 10; i++)
	{
		inventory.Add(i);
	}

	for (auto iter = inventory.Begin(); iter != inventory.End(); iter.Next())
	{
		std::cout << iter.CurrentItem() << std::endl;
	}

	return 0;
}