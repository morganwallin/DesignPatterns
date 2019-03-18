#pragma once
#include "Prototype.h"

class DrinkPrototype : public Prototype {
public:
	DrinkPrototype() {}
	std::string getName() const override { return name; }
	int getCost() const override { return cost; }
	std::shared_ptr<DrinkPrototype> clone() { return std::make_shared<DrinkPrototype>(); }
	void initialize(int pmCost, std::string pmName) { cost = pmCost; name = pmName; }
};