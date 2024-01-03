#include "ChainOfResponsibility2.h"
#include <iostream>

void ActionMan::DoAction()
{
	switch (ActionHelper->WhatAction())
	{
	case EAction::Fly:
	{
		std::cout << "날기 전에 준비를 합니다!" << std::endl;
		break;
	}
	case EAction::Jump:
	{
		std::cout << "점프하기 전에 준비를 합니다!" << std::endl;
		break;
	}
	case EAction::Sprint:
	{
		std::cout << "달리기 전에 준비를 합니다!" << std::endl;
		break;
	}
	}

	if (ActionHelper)
	{
		ActionHelper->DoAction();
	}
}

EAction ActionMan::WhatAction()
{
	return EAction::None;
}

void ActionMan::SetAction(IAction* ActionHelper)
{
	this->ActionHelper = ActionHelper;
}

void FlyHelper::DoAction()
{
	std::cout << "Fly하는 중입니다!!" << std::endl;
}

EAction FlyHelper::WhatAction()
{
	return EAction::Fly;
}

void JumpHelper::DoAction()
{
	std::cout << "Jump하는 중입니다!!" << std::endl;
}

EAction JumpHelper::WhatAction()
{
	return EAction::Jump;
}

void SprintHelper::DoAction()
{
	std::cout << "Sprint하는 중입니다!!" << std::endl;
}

EAction SprintHelper::WhatAction()
{
	return EAction::Sprint;
}
