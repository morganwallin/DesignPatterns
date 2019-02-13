#pragma once

#include <string>
#include <vector>
#include "Ingredient.hpp"
#include <algorithm>

class BakingRecepy
{
protected:
	std::string name;
	std::vector<Ingredient> neededIng;

public:
	BakingRecepy(std::string aName);
	BakingRecepy();
	virtual ~BakingRecepy() {};
	const std::string& getName() { return name; };
	bool isBakeable(std::vector<Ingredient>& availableIng);
	std::vector<Ingredient> getNeededIng() { return neededIng; };
	virtual void bakeIt()=0;
};

