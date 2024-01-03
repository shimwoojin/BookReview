#include "ChainOfResponsibility2.h"
#include <iostream>

void ActionMan::DoAction()
{
	switch (ActionHelper->WhatAction())
	{
	case EAction::Fly:
	{
		std::cout << "���� ���� �غ� �մϴ�!" << std::endl;
		break;
	}
	case EAction::Jump:
	{
		std::cout << "�����ϱ� ���� �غ� �մϴ�!" << std::endl;
		break;
	}
	case EAction::Sprint:
	{
		std::cout << "�޸��� ���� �غ� �մϴ�!" << std::endl;
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
	std::cout << "Fly�ϴ� ���Դϴ�!!" << std::endl;
}

EAction FlyHelper::WhatAction()
{
	return EAction::Fly;
}

void JumpHelper::DoAction()
{
	std::cout << "Jump�ϴ� ���Դϴ�!!" << std::endl;
}

EAction JumpHelper::WhatAction()
{
	return EAction::Jump;
}

void SprintHelper::DoAction()
{
	std::cout << "Sprint�ϴ� ���Դϴ�!!" << std::endl;
}

EAction SprintHelper::WhatAction()
{
	return EAction::Sprint;
}
