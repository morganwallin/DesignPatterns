#pragma once
#include "Component.h"

//Derived from Component, holds the beverage information
class ConcreteComponent : public Component {
protected:
	ConcreteComponent() {}
public:
	std::string getName() const override {
		return name;
	}
	int getCost() const override {
		return cost;
	}
};



class Coffee : public ConcreteComponent {
public:
	Coffee() { cost = 10; name = "Coffee"; }
};

class Espresso : public ConcreteComponent {
public:
	Espresso() { cost = 14; name = "Espresso"; }
};

class Tea : public ConcreteComponent {
public:
	Tea() { cost = 10; name = "Tea"; }
};

class Chocolate : public ConcreteComponent {
public:
	Chocolate() { cost = 12; name = "Chocolate"; }
};

