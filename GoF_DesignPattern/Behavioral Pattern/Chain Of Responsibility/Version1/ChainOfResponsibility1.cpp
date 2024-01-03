#include "ChainOfResponsibility1.h"
#include <iostream>

void ActionMan::Fly()
{
	FlyHelper->Fly();
}

void ActionChain::Fly()
{
	std::cout << "하늘을 날아요!!" << std::endl;
}
