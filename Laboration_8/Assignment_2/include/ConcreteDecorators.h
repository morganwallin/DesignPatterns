#pragma once
#include "Prototype.h"
#include "ConcreteComponent.h"
#include <memory>

class DecoratorPrototype : public Prototype {
private:
	std::shared_ptr<Prototype> nextComp; //Pointer to object to be decorated
	
public:
	DecoratorPrototype(std::shared_ptr<Prototype> comp) : nextComp(comp) {}
	DecoratorPrototype() {}
	std::string getName() const override { return nextComp->getName() + " + " + name; } // Returns updated name: 'Beverage name + extra + etc';
	int getCost() const override { return cost + nextComp->getCost(); } //Returns updated cost after the extra was added
	std::shared_ptr<DecoratorPrototype> clone(std::shared_ptr<Prototype> comp) { return std::make_shared<DecoratorPrototype>(comp); }
	void initialize(int pmCost, std::string pmName, std::shared_ptr<Prototype> comp) { cost = pmCost; name = pmName; nextComp = comp; }
};