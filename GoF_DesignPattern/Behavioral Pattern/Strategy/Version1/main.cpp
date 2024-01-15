#include "Strategy1.h"

int main()
{
	Market market;
	Person person;
	
	market.Sell(&person, "apple");
	market.Sell(&person, "banana");

	person.ShowItems();
	person.ShowMoney();

	market.ChangeStrategy(PriceStrategy::manysell_strategy);

	market.Sell(&person, "apple");
	market.Sell(&person, "banana");
	market.Sell(&person, "graph");

	person.ShowItems();
	person.ShowMoney();

	return 0;
}