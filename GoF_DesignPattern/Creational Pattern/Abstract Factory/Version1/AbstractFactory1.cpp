#include <iostream>
#include "AbstractFactory1.h"

Car* CompanyWJ::CreateCar(CarFactory& car_factory)
{
	Car* new_car = car_factory.CreateCar();
	new_car->CombineCarBody(car_factory.CreateCarBody());
	new_car->CombineHandle(car_factory.CreateHandle());
	new_car->CombineWheel(car_factory.CreateWheel());

	return new_car;
}

void Car::CombineWheel(Wheel* wheel)
{
	this->wheel = wheel;
}

void Car::CombineHandle(Handle* handle)
{
	this->handle = handle;
}

void Car::CombineCarBody(CarBody* car_body)
{
	this->car_body = car_body;
}

Wheel* SmallCarFactory::CreateWheel()
{
	Wheel* wheel = new Wheel;
	wheel->SetRadius(10.0f);
	return wheel;
}

Handle* SmallCarFactory::CreateHandle()
{
	Handle* handle = new Handle;
	handle->SetSize(10);
	return handle;
}

CarBody* SmallCarFactory::CreateCarBody()
{
	CarBody* car_body = new CarBody;
	car_body->SetSizeType(CarBody::SizeType::small);
	return car_body;
}

Wheel* BigCarFactory::CreateWheel()
{
	Wheel* wheel = new Wheel;
	wheel->SetRadius(20.0f);
	return wheel;
}

Handle* BigCarFactory::CreateHandle()
{
	Handle* handle = new Handle;
	handle->SetSize(20);
	return handle;
}

CarBody* BigCarFactory::CreateCarBody()
{
	CarBody* car_body = new CarBody;
	car_body->SetSizeType(CarBody::SizeType::big);
	return car_body;
}

std::ostream& operator<<(std::ostream& o, CarBody::SizeType size_type)
{
	switch (size_type)
	{
	case CarBody::SizeType::small:
		o << "small";
		break;
	case CarBody::SizeType::middle:
		o << "middle";
		break;
	case CarBody::SizeType::big:
		o << "big";
		break;
	}

	return o;
}
