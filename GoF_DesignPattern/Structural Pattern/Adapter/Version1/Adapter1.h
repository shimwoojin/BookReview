#pragma once
#include <iostream>

class Tissue
{
public:
	virtual void Sop()
	{
		std::cout << "Tissue�� ���� �������ϴ�." << std::endl;
	}
};

class Destructible
{
public:
	void Destroy()
	{
		std::cout << "�� ��ü�� �ı��մϴ�." << std::endl;
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