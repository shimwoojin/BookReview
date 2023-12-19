#pragma once
#include <iostream>

class Monster
{
public:
	Monster(float speed, float attack_damage) 
		: speed(speed), attack_damage(attack_damage) 
	{}

	//Clone ���� �� ���� �����ڿ� ���� -> ������ ������ ���� �� ���� ���縦 ��������� ��(��Ŀ���� ���� �ƴ� ����)
	Monster(const Monster& rhs)
	{
		speed = rhs.speed;
		attack_damage = rhs.attack_damage;
	}

	virtual Monster* Clone() = 0;

	void ShowInfo()
	{
		std::cout << "speed : " << speed << std::endl;
		std::cout << "attack_damage : " << attack_damage << std::endl << std::endl;
	}

private:
	float speed;
	float attack_damage;
};

class BlueSnail : public Monster
{
public:
	BlueSnail(float speed, float attack_damage)
		: Monster(speed, attack_damage)
	{}

	virtual Monster* Clone() override { return new BlueSnail(*this); }
};

class RedDrake : public Monster
{
public:
	RedDrake(float speed, float attack_damage)
		: Monster(speed, attack_damage)
	{}

	virtual Monster* Clone() override { return new RedDrake(*this); }
};