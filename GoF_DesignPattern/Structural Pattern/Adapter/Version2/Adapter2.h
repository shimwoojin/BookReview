#pragma once
#include <iostream>

class Tissue_V2
{
public:
	virtual void Sop()
	{
		std::cout << "Tissue�� ���� �������ϴ�." << std::endl;
	}
};

class Destructible_V2
{
public:
	virtual void Destroy()
	{
		std::cout << "�� ��ü�� �ı��մϴ�." << std::endl;
	}
};

class SoftDestructible : public Destructible_V2
{
public:
	virtual void Destroy() override
	{
		std::cout << "�ε巴�� ";
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