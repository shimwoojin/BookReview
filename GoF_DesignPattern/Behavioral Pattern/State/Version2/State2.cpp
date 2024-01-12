#include "State2.h"
#include "iostream"

IdleState2* CharacterState2::idle_state = new IdleState2;
AttackState2* CharacterState2::attack_state = new AttackState2;
UltState2* CharacterState2::ult_state = new UltState2;

Character2::Character2()
{
	state = CharacterState2::idle_state;
}

void Character2::MouseLeftClick()
{
	state->Activate(this);
}

void Character2::ChangeState(CharacterState2* state)
{
	this->state = state;
}

void IdleState2::Activate(Character2* character2)
{
	std::cout << "Idle 상태에서 Attack 상태로 전이됩니다" << std::endl;
	ChangeState(character2, CharacterState2::attack_state);
}

void AttackState2::Activate(Character2* character2)
{
	if (character2->ult_gauge >= 10)
	{
		character2->attack_count = 0;
		std::cout << "Attack 상태에서 Ult 상태로 전이됩니다" << std::endl;
		ChangeState(character2, CharacterState2::ult_state);
	}
	else if (character2->attack_count >= 3)
	{
		character2->attack_count = 0;
		std::cout << "Attack 상태에서 Idle 상태로 전이됩니다" << std::endl;
		ChangeState(character2, CharacterState2::idle_state);
	}
	else
	{
		character2->attack_count++;
		character2->ult_gauge++;
		std::cout << "Attack 상태가 지속됩니다" << std::endl;
	}
}

void UltState2::Activate(Character2* character2)
{
	character2->ult_gauge = 0;
	std::cout << "궁극기를 발동합니다" << std::endl;
	ChangeState(character2, CharacterState2::idle_state);
}

void CharacterState2::ChangeState(Character2* character2, CharacterState2* state)
{
	character2->ChangeState(state);
}
