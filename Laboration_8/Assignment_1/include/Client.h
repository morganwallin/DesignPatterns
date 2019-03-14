#pragma once

#include <memory>
#include "Game.h"
#include <sstream>

//Client class, used to run program
class Client {
public:
	//Constructor/Destructor
	Client() = default;
	~Client() = default;

	//Functions
	void run(); //Simulation
};

