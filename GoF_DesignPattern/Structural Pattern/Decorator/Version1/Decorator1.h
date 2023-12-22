#pragma once

class Pikachu
{
public:
	Pikachu() {}

	virtual float GetDamage() { return attack_damage; }

private:
	float attack_damage = 20.0f;
};

class PikachuDecorator_Heavy : public Pikachu
{
public:
	PikachuDecorator_Heavy(Pikachu* pikachu, float weight) : pikachu(pikachu), weight(weight) {}

public:
	virtual float GetDamage() override { return pikachu->GetDamage() * weight; }

private:
	Pikachu* pikachu;
	float weight;
};