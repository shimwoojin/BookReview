#include "Observer1.h"
#include <iostream>

Observer::~Observer()
{
}

void Observer::Update(Subject* subject)
{
	std::cout << subject->GetName() << "로부터 업데이트 하라는 요청이 있습니다 ! " << std::endl;
	std::cout << name << "을 업데이트 합니다 !" << std::endl;
}

Subject::~Subject()
{
}

void Subject::Attach(Observer* observer)
{
	observers.push_back(observer);
}

void Subject::Detach(Observer* observer)
{
	observers.remove(observer);
}

void Subject::Notify()
{
	for (Observer* observer : observers)
	{
		observer->Update(this);
	}
}
