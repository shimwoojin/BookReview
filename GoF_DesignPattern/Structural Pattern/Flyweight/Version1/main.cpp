#include "Flyweight1.h"
#include <iostream>

int main()
{
	FlyweightFactory flyweight_factory;
	FlyweightCollector flyweight_collector1("collector1");
	FlyweightCollector flyweight_collector2("collector2");

	Flyweight* flyweight1 = flyweight_factory.GetFlyweight("SomeName1");
	Flyweight* flyweight2 = flyweight_factory.GetFlyweight("SomeName2");
	Flyweight* flyweight3 = flyweight_factory.GetFlyweight("SomeName3");

	flyweight_collector1.AddFlyweight(flyweight1);
	flyweight_collector1.AddFlyweight(flyweight2);
							   
	flyweight_collector2.AddFlyweight(flyweight3);
	flyweight_collector2.AddFlyweight(flyweight1);

	flyweight_collector1.PrintAllFlyweightsHash();
	std::cout << '\n';
	flyweight_collector2.PrintAllFlyweightsHash();

	return 0;
}