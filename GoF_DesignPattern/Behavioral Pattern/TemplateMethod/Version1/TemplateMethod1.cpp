#include "TemplateMethod1.h"
#include <iostream>

void TemplateMethod::Activate()
{
	std::cout << "���ø� �޼��� Activate Start !" << std::endl;

	OnActivate();

	std::cout << "���ø� �޼��� Activate End !" << std::endl;
}

void DerivedTemplateMethod::OnActivate()
{
	std::cout << "�������̵带 ���� �߻� ������ ������! " << std::endl;
	std::cout << "Activate�� �񰡻��Լ�, Activate���� �Ҹ��� OnActivate�� �������̵��ϴ� ���� ���ø� �޼��� ! " << std::endl;
}
