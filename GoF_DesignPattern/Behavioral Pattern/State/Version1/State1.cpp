#include "State1.h"
#include "iostream"

Character::Character()
{
	StateMap["Idle"] = new IdleState(this);
	StateMap["Attack"] = new AttackState(this);
	StateMap["Ult"] = new UltState(this);

	state = StateMap["Idle"];
}

Character::~Character()
{
	for (auto& ele : StateMap)
	{
		delete ele.second;
	}
}

void Character::MouseLeftClick()
{
	state->Activate();
}

void Character::ChangeState(CharacterState* state)
{
	this->state = state;
}

CharacterState* Character::GetState(std::string state_name)
{
	return StateMap[state_name];
}

void IdleState::Activate()
{
	std::cout << "Idle ���¿��� Attack ���·� ���̵˴ϴ�" << std::endl;
	ChangeState(character->GetState("Attack"));
}

void AttackState::Activate()
{
	if (character->ult_gauge >= 10)
	{
		character->attack_count = 0;
		std::cout << "Attack ���¿��� Ult ���·� ���̵˴ϴ�" << std::endl;
		ChangeState(character->GetState("Ult"));
	}
	else if (character->attack_count >= 3)
	{
		character->attack_count = 0;
		std::cout << "Attack ���¿��� Idle ���·� ���̵˴ϴ�" << std::endl;
		ChangeState(character->GetState("Idle"));
	}
	else
	{
		character->attack_count++;
		character->ult_gauge++;
		std::cout << "Attack ���°� ���ӵ˴ϴ�" << std::endl;
	}
}

void UltState::Activate()
{
	character->ult_gauge = 0;
	std::cout << "�ñر⸦ �ߵ��մϴ�" << std::endl;
	ChangeState(character->GetState("Idle"));
}

void CharacterState::ChangeState(CharacterState* state)
{
	character->ChangeState(state);
}
