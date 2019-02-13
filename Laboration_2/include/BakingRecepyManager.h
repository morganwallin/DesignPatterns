#pragma once
#include <string>
#include "BakingRecepy.h"
#include "Pizza.h"
#include "Scones.h"
#include "Kladdkaka.h"
#include "Sockerkaka.h"
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "NoBakingException.h"

class BakingRecepyManager
{
private:
	std::vector<std::shared_ptr<BakingRecepy>> brVector;
	std::vector<Ingredient> availableIngredient;
public:
	BakingRecepyManager(std::string fileName);
	~BakingRecepyManager();
	bool hasAnotherRecepy();
	std::shared_ptr<BakingRecepy> getNextBakingRecepy();
	std::vector<std::shared_ptr<BakingRecepy>>& getBrVector() { return brVector; };
	std::vector<Ingredient> getIngredients() { return availableIngredient; };

};

