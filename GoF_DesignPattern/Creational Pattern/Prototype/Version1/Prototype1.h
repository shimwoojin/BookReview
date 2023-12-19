#pragma once
#include <vector>
#include "Prototype1_Components.h"
#include <cassert>

class MonsterFactory
{
public:
	template<typename T>
	void Register(float speed, float attack_damage)
	{
		static_assert(_STD is_base_of_v<Monster, T>, "T is not derived from Monster Class");

		MonsterPrototypes.push_back(new T(speed, attack_damage));
	}

	Monster* Clone(int index)
	{
		assert(index >= 0 && index < MonsterPrototypes.size());

		return MonsterPrototypes[index]->Clone();
	}

	size_t RegisterdMonsterSize()
	{
		return MonsterPrototypes.size();
	}

private:
	std::vector<Monster*> MonsterPrototypes;
};