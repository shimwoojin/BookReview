#include "Visitor1.h"
#include <iostream>

void DerivedEquipment1::Accept(EquipmentVisitor& visitor)
{
	visitor.VisitDerivedEquipment1(this);
}

void DerivedEquipment2::Accept(EquipmentVisitor& visitor)
{
	visitor.VisitDerivedEquipment2(this);
}

void DerivedEquipment3::Accept(EquipmentVisitor& visitor)
{
	visitor.VisitDerivedEquipment3(this);
}

void NameCollectVisitor::ShowNames()
{
	for (std::string name : names)
	{
		std::cout << "name : " << name << std::endl;
	}
}

void NameCollectVisitor::VisitDerivedEquipment1(DerivedEquipment1* derived_equipment1)
{
	names.push_back(derived_equipment1->GetName());
}

void NameCollectVisitor::VisitDerivedEquipment2(DerivedEquipment2* derived_equipment2)
{
	names.push_back(derived_equipment2->GetName());
}

void NameCollectVisitor::VisitDerivedEquipment3(DerivedEquipment3* derived_equipment3)
{
	names.push_back(derived_equipment3->GetName());
}

void PricingVisitor::VisitDerivedEquipment1(DerivedEquipment1* derived_equipment1)
{
	total_price += derived_equipment1->GetPrice();
}

void PricingVisitor::VisitDerivedEquipment2(DerivedEquipment2* derived_equipment2)
{
	total_price += derived_equipment2->GetPrice();
}

void PricingVisitor::VisitDerivedEquipment3(DerivedEquipment3* derived_equipment3)
{
	total_price += derived_equipment3->GetPrice();
}
