#include "Composite1.h"

int Composite::GetPrice()
{
	int price = 0;
	for (Component* child : childs)
	{
		price += child->GetPrice();
	}

	return price;
}

void Composite::Add(Component* component)
{
	childs.push_back(component);
}

void Composite::Remove(Component* component)
{
	for(auto iter = childs.begin(); iter != childs.end(); iter++)
	{
		if (*iter == component)
		{
			childs.erase(iter);
			break;
		}
	}
}
