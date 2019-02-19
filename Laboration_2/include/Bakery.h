#pragma once

#include "BakingRecepyManager.h"
#include <iostream>

//Bakery class is used as a client, runs the simulation for a bakery.
class Bakery
{
private:
	BakingRecepyManager bakingRecepyManager;
	
public:
	Bakery();
	void runBakery();
	virtual ~Bakery() = default;

	BakingRecepyManager& getBakingRecepyManager() { return bakingRecepyManager; };
};

