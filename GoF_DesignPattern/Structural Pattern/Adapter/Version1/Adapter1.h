#pragma once
#include <iostream>

class Tissue
{
public:
	virtual void Sop()
	{
		std::cout << "Tissue가 물에 젖었습니다." << std::endl;
	}
};

class Destructible
{
public:
	void Destroy()
	{
		std::cout << "이 물체를 파괴합니다." << std::endl;
	}
};

class ToiletTissue : public Tissue, private Destructible
{
public:
	virtual void Sop() override
	{
		Tissue::Sop();
		Destroy();
	}
};