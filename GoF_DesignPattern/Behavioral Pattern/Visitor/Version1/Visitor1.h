#pragma once
#include <string>
#include <vector>

class EquipmentVisitor;

class Equipment
{
public:
	Equipment(std::string name, size_t price) 
		: name(name), price(price) {}

	std::string GetName() { return name; }
	size_t GetPrice() { return price; }

	virtual void Accept(EquipmentVisitor& visitor) = 0;

private:
	std::string name;
	size_t price;
};

class DerivedEquipment1 : public Equipment
{
public:
	DerivedEquipment1(std::string name, size_t price) 
		: Equipment(name, price) {}

	virtual void Accept(EquipmentVisitor& visitor);
};

class DerivedEquipment2 : public Equipment
{
public:
	DerivedEquipment2(std::string name, size_t price)
		: Equipment(name, price) {}

	virtual void Accept(EquipmentVisitor& visitor);
};

class DerivedEquipment3 : public Equipment
{
public:
	DerivedEquipment3(std::string name, size_t price)
		: Equipment(name, price) {}

	virtual void Accept(EquipmentVisitor& visitor);
};

class EquipmentVisitor
{
public:
	virtual void VisitDerivedEquipment1(DerivedEquipment1* derived_equipment1) {}
	virtual void VisitDerivedEquipment2(DerivedEquipment2* derived_equipment2) {}
	virtual void VisitDerivedEquipment3(DerivedEquipment3* derived_equipment3) {}
};

class NameCollectVisitor : public EquipmentVisitor
{
public:
	void ShowNames();

	virtual void VisitDerivedEquipment1(DerivedEquipment1* derived_equipment1) override;
	virtual void VisitDerivedEquipment2(DerivedEquipment2* derived_equipment2) override;
	virtual void VisitDerivedEquipment3(DerivedEquipment3* derived_equipment3) override;

private:
	std::vector<std::string> names;
};

class PricingVisitor : public EquipmentVisitor
{
public:
	size_t GetTotalPrice() { return total_price; }

	virtual void VisitDerivedEquipment1(DerivedEquipment1* derived_equipment1) override;
	virtual void VisitDerivedEquipment2(DerivedEquipment2* derived_equipment2) override;
	virtual void VisitDerivedEquipment3(DerivedEquipment3* derived_equipment3) override;

private:
	size_t total_price = 0;
};