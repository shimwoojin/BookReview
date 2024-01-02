#include "Flyweight1.h"
#include <iostream>

Flyweight* FlyweightFactory::GetFlyweight(std::string key)
{
	if (FlyweightMap.find(key) == FlyweightMap.end())
	{
		FlyweightMap[key] = new Flyweight(key);
		return FlyweightMap[key];
	}
	else
	{
		return FlyweightMap[key];
	}
}

FlyweightFactory::~FlyweightFactory()
{
	for (auto& fm : FlyweightMap)
	{
		if (fm.second != nullptr)
		{
			delete fm.second;
		}
	}
}

size_t Flyweight::GetHash()
{
	return hash(name);
}

void FlyweightCollector::AddFlyweight(Flyweight* flyweight)
{
	if (flyweight)
	{
		flyweights.push_back(flyweight);
	}
}

void FlyweightCollector::PrintAllFlyweightsHash()
{
	int count = 0;
	for (auto& f : flyweights)
	{
		++count;
		std::cout << name << "'s " << count << " Flyweight's Hash : " << f->GetHash() << " and Name : " << f->GetName() << '\n';
	}
}
