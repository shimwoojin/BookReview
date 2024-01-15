#include "Visitor1.h"
#include <iostream>

int main()
{
	DerivedEquipment1 derived_equipment1("equip1", 10);
	DerivedEquipment2 derived_equipment2("equip2", 20);
	DerivedEquipment3 derived_equipment3("equip3", 30);

	PricingVisitor pricing_visitor;
	NameCollectVisitor namecollect_visitor;

	derived_equipment1.Accept(pricing_visitor);
	derived_equipment2.Accept(pricing_visitor);
	derived_equipment3.Accept(pricing_visitor);

	derived_equipment1.Accept(namecollect_visitor);
	derived_equipment2.Accept(namecollect_visitor);
	derived_equipment3.Accept(namecollect_visitor);

	namecollect_visitor.ShowNames();
	std::cout << "모든 물건의 총합은 " << pricing_visitor.GetTotalPrice() << "입니다. " << std::endl;

	return 0;
}