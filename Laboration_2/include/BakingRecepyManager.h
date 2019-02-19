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

//Class BakingRecepyManager, reads available ingredients from pantry
//and holds information regarding which recepies are available
class BakingRecepyManager
{
private:
	std::vector<std::shared_ptr<BakingRecepy>> bakingRecepies;
	std::vector<Ingredient> availableIngredients;
	bool hasAnotherRecepy();

public:
	explicit BakingRecepyManager(std::string fileName);
	~BakingRecepyManager() = default;
	//Gets next BakingRecepy from vector bakingRecepies, throws NoBakingException if no more recepies are available
	std::shared_ptr<BakingRecepy> getNextBakingRecepy();
	std::vector<std::shared_ptr<BakingRecepy>>& getBakingRecepies() { return bakingRecepies; };
	std::vector<Ingredient> getIngredients() { return availableIngredients; };

};

