#pragma once
#include <list>
#include <string>

class Subject;

class Observer
{
public:
	Observer(std::string name) : name(name) {}
	virtual ~Observer();
	virtual void Update(Subject* subject);

private:
	std::string name;
};

class Subject
{
public:
	Subject(std::string name) : name(name) {}
	virtual ~Subject();

	virtual void Attach(Observer* observer);
	virtual void Detach(Observer* observer);
	virtual void Notify();

	std::string GetName() { return name; }

private:
	std::list<Observer*> observers;
	std::string name;
};