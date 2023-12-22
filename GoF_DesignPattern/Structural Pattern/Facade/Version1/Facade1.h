#pragma once

class Man
{
public:
	void AddHappiness(int happiness) { this->happiness += happiness; }
	int GetHappiness() { return happiness; }

private:
	int happiness = 0;
};

class Sleep
{
public:
	bool EnsureGoodNight(Man* man, int hours);
};

class GirlFriend
{
public:
	void GoodNightKiss(Man* man);
};

class Bed
{
public:
	enum class Type
	{
		hard,
		soft
	};

public:
	Bed(Type type) : type(type) {}

public:
	bool IsSoftBed() { return type == Type::soft; }

private:
	Type type;
};

class GoodNightMaker
{
public:
	void HaveAGoodNight(Man* man, int sleep_horus, Bed::Type bed_type);
};