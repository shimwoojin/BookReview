#pragma once
#include <vector>

template<typename T>
class Inventory;

template<typename T>
class InventoryIterator;

template<typename Item>
class Inventory
{
public:
	using Iterator = InventoryIterator<Item>;
	friend class Iterator;

public:
	Iterator Begin();
	Iterator End();

	void Add(Item item);
	void Remove(Item item);

private:
	std::vector<Item> items;
};

template<typename Item>
class IIterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Item CurrentItem() = 0;
};

template<typename Item>
class InventoryIterator : public IIterator<Item>
{
public:
	InventoryIterator(Inventory<Item>* inventory, bool bBegin = true) 
		: inventory(inventory) 
	{
		if (bBegin)
		{
			First();
		}
		else
		{
			current_index = inventory->items.size();
		}
	}

	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual Item CurrentItem();

	bool operator !=(const InventoryIterator<Item> rhs) const
	{
		return current_index != rhs.current_index;
	}

private:
	Inventory<Item>* inventory;
	size_t current_index;
};

template<typename Item>
inline void InventoryIterator<Item>::First()
{
	current_index = 0;
}

template<typename Item>
inline void InventoryIterator<Item>::Next()
{
	current_index++;
}

template<typename Item>
inline bool InventoryIterator<Item>::IsDone()
{
	return inventory->items.size() <= current_index;
}

template<typename Item>
inline Item InventoryIterator<Item>::CurrentItem()
{
	return inventory->items[current_index];
}

template<typename Item>
inline typename Inventory<Item>::Iterator Inventory<Item>::Begin()
{
	return InventoryIterator<Item>(this, true);
}

template<typename Item>
inline typename Inventory<Item>::Iterator Inventory<Item>::End()
{
	return InventoryIterator<Item>(this, false);
}

template<typename Item>
inline void Inventory<Item>::Add(Item item)
{
	items.push_back(item);
}

template<typename Item>
inline void Inventory<Item>::Remove(Item item)
{
	items.erase(item);
}
