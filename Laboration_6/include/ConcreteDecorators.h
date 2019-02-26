#pragma once
#include "Component.h"
#include <memory>

//Derived from Component, holds information about extras to be added to the ConcreteComponent
class ConcreteDecorators : public Component
{
protected:
	std::shared_ptr<Component> nextComp; //Pointer to object to be decorated

public:
	ConcreteDecorators(std::shared_ptr<Component> comp) : nextComp(comp) {}

	// Returns updated name: 'Beverage name + extra + etc';
	std::string getName() const override {
		return nextComp->getName() + " + " + name;
	}
	//Returns updated cost after the extra was added
	int getCost() const override {
		return cost + nextComp->getCost();
	}
};

class Sugar : public ConcreteDecorators {
public:
	Sugar(std::shared_ptr<Component> comp) : ConcreteDecorators(comp) { name = "Sugar"; cost = 1; }
};

class Milk : public ConcreteDecorators {
public:
	Milk(std::shared_ptr<Component> comp) : ConcreteDecorators(comp) { name = "Milk"; cost = 1; }
};

class Cream : public ConcreteDecorators {
public:
	Cream(std::shared_ptr<Component> comp) : ConcreteDecorators(comp) { name = "Cream"; cost = 2; }
};

class WhippedCream : public ConcreteDecorators {
public:
	WhippedCream(std::shared_ptr<Component> comp) : ConcreteDecorators(comp) { name = "Whipped Cream"; cost = 5; }
};

