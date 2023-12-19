#include "Prototype1.h"

int main()
{
	MonsterFactory monster_factory;

	monster_factory.Register<BlueSnail>(10.0f, 10.0f);
	monster_factory.Register<BlueSnail>(20.0f, 10.0f);
	monster_factory.Register<BlueSnail>(20.0f, 20.0f);

	monster_factory.Register<RedDrake>(30.0f, 30.0f);
	monster_factory.Register<RedDrake>(20.0f, 20.0f);
	monster_factory.Register<RedDrake>(40.0f, 50.0f);

	std::cout << "Registered MonsterSize : " << monster_factory.RegisterdMonsterSize() << std::endl << std::endl;

	Monster* m1 = monster_factory.Clone(2);
	Monster* m2 = monster_factory.Clone(5);

	m1->ShowInfo();
	m2->ShowInfo();

	return 0;
}