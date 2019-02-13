#pragma once

#include "BakingRecepyManager.h"

class Bakery
{
private:
	BakingRecepyManager brm;
public:
	Bakery(std::string fileName);
	virtual ~Bakery();

	BakingRecepyManager& getBrm() { return brm; };
};

