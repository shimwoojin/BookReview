#pragma once
#include <string>

class RectureBridge
{
public:
	void ClassStart();
	void TakeBreakTime();
	void GiveGrades();
	void SetTeaher(class Teacher* teacher);

private:
	class Teacher* teacher = nullptr;
};

class Teacher
{
public:
	Teacher(std::string name) : name(name) {}

	void StartTeach();
	void StopTeach();
	void ScoreStudent();

private:
	std::string name;
};