#pragma once
#include <iostream>

class Tissue_V2
{
public:
	virtual void Sop()
	{
		std::cout << "Tissue가 물에 젖었습니다." << std::endl;
	}
};

class Destructible_V2
{
public:
	virtual void Destroy()
	{
		std::cout << "이 물체를 파괴합니다." << std::endl;
	}
};

class SoftDestructible : public Destructible_V2
{
public:
	virtual void Destroy() override
	{
		std::cout << "부드럽게 ";
		__super::Destroy();
	}
};

class ToiletTissue_V2 : public Tissue_V2
{
public:
	virtual void Sop() override
	{
		Tissue_V2::Sop();
		destructible->Destroy();
	}
	
	void SetDestructible(Destructible_V2* destructible)
	{
		this->destructible = destructible;
	}

private:
	Destructible_V2* destructible;
};