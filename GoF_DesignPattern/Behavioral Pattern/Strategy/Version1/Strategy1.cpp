#include "Strategy1.h"
#include <iostream>

DefaultStrategy* PriceStrategy::default_strategy = new DefaultStrategy;
ManySellStrategy* PriceStrategy::manysell_strategy = new ManySellStrategy;
LuxuryStrategy* PriceStrategy::luxury_strategy = new LuxuryStrategy;

Market::Market()
{
	price_strategy = PriceStrategy::default_strategy;

	items["apple"] = 10;
	items["banana"] = 20;
	items["graph"] = 30;
}

void Market::Sell(Person* person, std::string item_name)
{
	size_t price = items[item_name] * price_strategy->DisCountPercent();

	person->Buy(item_name, price);
}

void Market::ChangeStrategy(PriceStrategy* price_strategy)
{
	this->price_strategy = price_strategy;
}

Person::Person()
{
	money = 100;
}

void Person::Buy(std::string item_name, size_t price)
{
	if (money >= price)
	{
		money -= price;
		items.push_back(item_name);
	}
	else
	{
		std::cout << "구매 실패! " << std::endl;
	}
}

void Person::ShowMoney()
{
	std::cout << "남은 돈은 " << money << "$ 입니다" << std::endl;
}

void Person::ShowItems()
{
	for (const auto& item : items)
	{
		std::cout << "item : " << item << std::endl;
	}
}
