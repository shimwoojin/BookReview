#pragma once
#include <map>
#include <string>

class Character2;
class IdleState2;
class AttackState2;
class UltState2;

class CharacterState2
{
public:
	static IdleState2* idle_state;
	static AttackState2* attack_state;
	static UltState2* ult_state;

public:
	virtual void Activate(Character2* character2) = 0;
	void ChangeState(Character2* character2, CharacterState2* state);
};

class Character2
{
	friend class CharacterState2;

public:
	Character2();

public:
	void MouseLeftClick();

private:
	void ChangeState(CharacterState2* state);

public:
	size_t attack_count = 0;
	size_t ult_gauge = 0;

private:
	CharacterState2* state = nullptr;
};

class IdleState2 : public CharacterState2
{
public:
	virtual void Activate(Character2* character2) override;
};

class AttackState2 : public CharacterState2
{
public:
	virtual void Activate(Character2* character2) override;
};

class UltState2 : public CharacterState2
{
public:
	virtual void Activate(Character2* character2) override;
};