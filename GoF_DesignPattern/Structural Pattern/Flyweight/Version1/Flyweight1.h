#pragma once
#include <map>
#include <string>
#include <vector>

class Flyweight;

class FlyweightFactory
{
public:
	Flyweight* GetFlyweight(std::string key);
	~FlyweightFactory();

private:
	std::map<std::string, Flyweight*> FlyweightMap;
};

class Flyweight
{
	friend class FlyweightFactory;

private:
	Flyweight(std::string name) : name(name) {}

public:
	size_t GetHash();
	std::string GetName() { return name; }

private:
	std::string name;
	std::hash<std::string> hash;
};

class FlyweightCollector
{
public:
	FlyweightCollector(std::string name) : name(name) {}

public:
	void AddFlyweight(Flyweight* flyweight);
	void PrintAllFlyweightsHash();

private:
	std::vector<Flyweight*> flyweights;
	std::string name;
};