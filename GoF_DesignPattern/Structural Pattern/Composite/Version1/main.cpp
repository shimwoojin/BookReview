#include "Composite1.h"
#include <iostream>

void AddBrick(Composite* composite, int price, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::string name = "brick" + std::to_string(i);
		Brick* brick = new Brick(name, price);
		composite->Add(brick);
	}
}

int main(int argc, char* argv[])
{
	House house("house");
	
	Wall wall1("wall1");
	Wall wall2("wall2");
	Wall wall3("wall3");
	Wall wall4("wall4");
	
	Roof roof("roof");

	AddBrick(&wall1, 10, 20);
	AddBrick(&wall2, 10, 20);
	AddBrick(&wall3, 10, 20);
	AddBrick(&wall4, 10, 20);

	AddBrick(&roof, 20, 50);

	house.Add(&wall1);
	house.Add(&wall2);
	house.Add(&wall3);
	house.Add(&wall4);
	house.Add(&roof);

	std::cout << "Total House Price : " << house.GetPrice() << std::endl;

	return 0;
}