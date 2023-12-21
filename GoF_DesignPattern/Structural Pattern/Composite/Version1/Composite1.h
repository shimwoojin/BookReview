#pragma once
#include "Composite1_Sub.h"
#include <string>
#include <vector>

class Component
{
public:
	virtual ~Component() {}

	virtual int GetPrice() { return int(); }

	virtual void Add(Component* component) {}
	virtual void Remove(Component* component) {}
	virtual bool IsParent() { return false; }

	std::string GetName() { return name; }

protected:
	Component(std::string name) : name(name) {}

private:
	std::string name;
};

class Composite : public Component
{
public:
	virtual int GetPrice() override;

	virtual void Add(Component* component) override;
	virtual void Remove(Component* component) override;
	virtual bool IsParent() override { return true; }

protected:
	Composite(std::string name) : Component(name) {}

private:
	std::vector<Component*> childs;
};

class House : public Composite
{
public:
	House(std::string name) : Composite(name) {}
};

class Wall : public Composite
{
public:
	Wall(std::string name) : Composite(name) {}
};

class Roof : public Composite
{
public:
	Roof(std::string name) : Composite(name) {}
};

class Leaf : public Component
{
public:
	virtual int GetPrice() override { return price; }

protected:
	Leaf(std::string name, int price) : Component(name), price(price) {}

private:
	int price;
};

class Brick : public Leaf
{
public:
	Brick(std::string name, int price) : Leaf(name, price) {}
};