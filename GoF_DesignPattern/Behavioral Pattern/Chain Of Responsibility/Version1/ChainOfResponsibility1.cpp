#include "ChainOfResponsibility1.h"
#include <iostream>

void ActionMan::Fly()
{
	FlyHelper->Fly();
}

void ActionChain::Fly()
{
	std::cout << "�ϴ��� ���ƿ�!!" << std::endl;
}
