#pragma once

#include <string>
#include <vector>
#include "Ingredient.hpp"
#include <algorithm>

//BakingRecepy is a true virtual class for Baking Recepies.
//Contains name and which ingredients are needed.
class BakingRecepy
{
protected:
	std::string name;
	std::vector<Ingredient> neededIngredients;
	explicit BakingRecepy(std::string aName);
	BakingRecepy();
	virtual ~BakingRecepy() = default;

public:
	const std::string& getName() { return name; };
	bool isBakeable(std::vector<Ingredient>& availableIngredients);
	std::vector<Ingredient> getNeededIng() { return neededIngredients; };
	virtual void bakeIt()=0;
};

