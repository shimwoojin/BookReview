#pragma once
#include <map>
#include <string>

class Character;

class CharacterState
{
public:
	CharacterState(Character* character) : character(character) {}
	virtual void Activate() = 0;
	void ChangeState(CharacterState* state);

protected:
	Character* character;
};

class Character
{
	friend class CharacterState;

public:
	Character();
	virtual ~Character();

public:
	void MouseLeftClick();

	CharacterState* GetState(std::string state_name);

private:
	void ChangeState(CharacterState* state);

public:
	size_t attack_count = 0;
	size_t ult_gauge = 0;

private:
	std::map<std::string, CharacterState*> StateMap;

	CharacterState* state = nullptr;
};

class IdleState : public CharacterState
{
public:
	IdleState(Character* character)
		: CharacterState(character) {}

	virtual void Activate();
};

class AttackState : public CharacterState
{
public:
	AttackState(Character* character)
		: CharacterState(character) {}

	virtual void Activate();
};

class UltState : public CharacterState
{
public:
	UltState(Character* character) 
		: CharacterState(character) {}

	virtual void Activate();
};