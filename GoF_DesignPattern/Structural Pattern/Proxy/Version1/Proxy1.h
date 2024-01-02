#pragma once
#include <set>

class Person;
class Mom;
class Son;

class Device
{
public:
	virtual ~Device() {}
	
	virtual void TurnOn() abstract;
	virtual void TurnOff() abstract;
};

class Computer : public Device
{
	friend class ComputerProxy;

private:
	virtual void TurnOn();
	virtual void TurnOff();

private:
	Computer() {}
};

class ComputerProxy : public Device
{
public:
	~ComputerProxy();

public:
	void TogglePower(Person* person);

	template<typename T>
	void AddAccessible(T* person);

private:
	virtual void TurnOn();
	virtual void TurnOff();

private:
	Device* operator->();

private:
	Device* computer = nullptr;
	bool bTurnOn = false;

	std::set<Person*> AccessiblePeople;
};

class Person
{
};

class Mom : public Person
{
};

class Son : public Person
{
};

template<typename T>
void ComputerProxy::AddAccessible(T* person)
{
	static_assert(std::is_base_of_v<Person, T>, "T Must be Derived From Person Class!!");
	static_assert(!std::is_same_v<Son, T>, "Son can't access to computer!!");

	AccessiblePeople.insert(person);
}