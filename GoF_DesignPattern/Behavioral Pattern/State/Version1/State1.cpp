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
	std::cout << "Idle 상태에서 Attack 상태로 전이됩니다" << std::endl;
	ChangeState(character->GetState("Attack"));
}

void AttackState::Activate()
{
	if (character->ult_gauge >= 10)
	{
		character->attack_count = 0;
		std::cout << "Attack 상태에서 Ult 상태로 전이됩니다" << std::endl;
		ChangeState(character->GetState("Ult"));
	}
	else if (character->attack_count >= 3)
	{
		character->attack_count = 0;
		std::cout << "Attack 상태에서 Idle 상태로 전이됩니다" << std::endl;
		ChangeState(character->GetState("Idle"));
	}
	else
	{
		character->attack_count++;
		character->ult_gauge++;
		std::cout << "Attack 상태가 지속됩니다" << std::endl;
	}
}

void UltState::Activate()
{
	character->ult_gauge = 0;
	std::cout << "궁극기를 발동합니다" << std::endl;
	ChangeState(character->GetState("Idle"));
}

void CharacterState::ChangeState(CharacterState* state)
{
	character->ChangeState(state);
}
