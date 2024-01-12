#include "Observer1.h"
#include <iostream>

Observer::~Observer()
{
}

void Observer::Update(Subject* subject)
{
	std::cout << subject->GetName() << "�κ��� ������Ʈ �϶�� ��û�� �ֽ��ϴ� ! " << std::endl;
	std::cout << name << "�� ������Ʈ �մϴ� !" << std::endl;
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
