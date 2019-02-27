#pragma once

#include "Menu.h"
#include "ConcreteComponent.h"
#include "ConcreteDecorators.h"
#include <memory>

//Client class, runs the simulation
class Client
{
private:
	//Data members
	std::shared_ptr<Menu> menu;
	std::shared_ptr<Component> beverage;

public:
	//Constructor/Destructor
	Client();
	~Client() = default;

	//Functions
	void run(); //Simulation
	
};
