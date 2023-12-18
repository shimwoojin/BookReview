#include "AbstractFactory1.h"

int main()
{
	SmallCarFactory small_car_factory;
	BigCarFactory big_car_factory;

	Car* car1 = CompanyWJ::CreateCar(small_car_factory);
	Car* car2 = CompanyWJ::CreateCar(big_car_factory);

	car1->ShowCarInfo();
	car2->ShowCarInfo();

	return 0;
}