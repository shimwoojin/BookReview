#pragma once
#include "CarComponents.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, CarBody::SizeType size_type);

class Car
{
public:
	void ShowCarInfo()
	{
		using namespace std;

		cout << "car_body size : " << car_body->GetSizeType() << endl;
		cout << "handle size : " << handle->GetSize() << endl;
		cout << "wheel radius : " << wheel->GetRadius() << endl << endl;
	}

public:
	void CombineWheel(Wheel* wheel);
	void CombineHandle(Handle* handle);
	void CombineCarBody(CarBody* car_body);

private:
	Wheel* wheel = nullptr;
	Handle* handle = nullptr;
	CarBody* car_body = nullptr;
};

class CarFactory
{
public:
	virtual class Car* CreateCar() { return new Car; }
	virtual class Wheel* CreateWheel() = 0;
	virtual class Handle* CreateHandle() = 0;
	virtual class CarBody* CreateCarBody() = 0;
};

class SmallCarFactory : public CarFactory
{
public:
	virtual class Wheel* CreateWheel();
	virtual class Handle* CreateHandle();
	virtual class CarBody* CreateCarBody();
};

class BigCarFactory : public CarFactory
{
public:
	virtual class Wheel* CreateWheel();
	virtual class Handle* CreateHandle();
	virtual class CarBody* CreateCarBody();
};

class CompanyWJ
{
public:
	static Car* CreateCar(CarFactory& car_factory);
};
