#include "TemplateMethod1.h"
#include <iostream>

void TemplateMethod::Activate()
{
	std::cout << "템플릿 메서드 Activate Start !" << std::endl;

	OnActivate();

	std::cout << "템플릿 메서드 Activate End !" << std::endl;
}

void DerivedTemplateMethod::OnActivate()
{
	std::cout << "오버라이드를 통해 추상 연산을 재정의! " << std::endl;
	std::cout << "Activate는 비가상함수, Activate에서 불리는 OnActivate는 오버라이드하는 것이 템플릿 메서드 ! " << std::endl;
}
