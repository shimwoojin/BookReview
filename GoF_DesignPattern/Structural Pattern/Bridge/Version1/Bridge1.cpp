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
	std::cout << name << "선생님이 가르치기 시작합니다." << std::endl;
}

void Teacher::StopTeach()
{
	std::cout << name << "선생님이 가르치기를 멈춥니다." << std::endl;
}

void Teacher::ScoreStudent()
{
	std::cout << name << "선생님이 학생에게 점수를 줍니다." << std::endl;
}
