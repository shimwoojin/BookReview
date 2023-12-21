#include "Bridge1.h"
#include <iostream>

void RectureBridge::ClassStart()
{
	if (teacher)
	{
		teacher->StartTeach();
	}
}

void RectureBridge::TakeBreakTime()
{
	if (teacher)
	{
		teacher->StopTeach();
	}
}

void RectureBridge::GiveGrades()
{
	if (teacher)
	{
		teacher->ScoreStudent();
	}
}

void RectureBridge::SetTeaher(Teacher* teacher)
{
	this->teacher = teacher;
}

void Teacher::StartTeach()
{
	std::cout << name << "�������� ����ġ�� �����մϴ�." << std::endl;
}

void Teacher::StopTeach()
{
	std::cout << name << "�������� ����ġ�⸦ ����ϴ�." << std::endl;
}

void Teacher::ScoreStudent()
{
	std::cout << name << "�������� �л����� ������ �ݴϴ�." << std::endl;
}
