#pragma once
#include <iostream>

class Monster
{
public:
	Monster(float speed, float attack_damage) 
		: speed(speed), attack_damage(attack_damage) 
	{}

	//Clone 연산 시 복사 생성자에 의존 -> 포인터 변수가 있을 시 깊은 복사를 수행해줘야 함(매커니즘에 따라 아닐 수도)
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