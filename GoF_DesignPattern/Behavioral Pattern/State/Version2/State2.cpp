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
	std::cout << "Idle ���¿��� Attack ���·� ���̵˴ϴ�" << std::endl;
	ChangeState(character2, CharacterState2::attack_state);
}

void AttackState2::Activate(Character2* character2)
{
	if (character2->ult_gauge >= 10)
	{
		character2->attack_count = 0;
		std::cout << "Attack ���¿��� Ult ���·� ���̵˴ϴ�" << std::endl;
		ChangeState(character2, CharacterState2::ult_state);
	}
	else if (character2->attack_count >= 3)
	{
		character2->attack_count = 0;
		std::cout << "Attack ���¿��� Idle ���·� ���̵˴ϴ�" << std::endl;
		ChangeState(character2, CharacterState2::idle_state);
	}
	else
	{
		character2->attack_count++;
		character2->ult_gauge++;
		std::cout << "Attack ���°� ���ӵ˴ϴ�" << std::endl;
	}
}

void UltState2::Activate(Character2* character2)
{
	character2->ult_gauge = 0;
	std::cout << "�ñر⸦ �ߵ��մϴ�" << std::endl;
	ChangeState(character2, CharacterState2::idle_state);
}

void CharacterState2::ChangeState(Character2* character2, CharacterState2* state)
{
	character2->ChangeState(state);
}
