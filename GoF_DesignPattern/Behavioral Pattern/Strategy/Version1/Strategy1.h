#pragma once
#include <string>
#include <vector>
#include <map>

class Person;
class DefaultStrategy;
class ManySellStrategy;
class LuxuryStrategy;

class PriceStrategy
{
public:
	static DefaultStrategy* default_strategy;
	static ManySellStrategy* manysell_strategy;
	static LuxuryStrategy* luxury_strategy;

public:
	virtual float DisCountPercent() { return 1.0f; };
};

class Market
{
public:
	Market();

	void Sell(Person* person, std::string item_name);
	void ChangeStrategy(PriceStrategy* price_strategy);

private:
	PriceStrategy* price_strategy = nullptr;
	std::map<std::string, size_t> items;
};

class Person
{
public:
	Person();

	void Buy(std::string item_name, size_t price);
	void ShowMoney();
	void ShowItems();

private:
	std::vector<std::string> items;
	size_t money;
};

class DefaultStrategy : public PriceStrategy
{
public:
	virtual float DisCountPercent() { return 1.0f; };
};

class ManySellStrategy : public PriceStrategy
{
public:
	virtual float DisCountPercent() { return 0.7f; };
};

class LuxuryStrategy : public PriceStrategy
{
public:
	virtual float DisCountPercent() { return 1.5f; };
};