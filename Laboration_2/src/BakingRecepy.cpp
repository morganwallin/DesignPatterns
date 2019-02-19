#include "BakingRecepy.h"



BakingRecepy::BakingRecepy(std::string aName)
{
	name = aName;
}

BakingRecepy::BakingRecepy() {
	name = typeid(this).name();
}

bool BakingRecepy::isBakeable(std::vector<Ingredient>& availableIngredients) {
	for(auto &neededIngredient : neededIngredients) {
		if (std::find(availableIngredients.begin(), availableIngredients.end(), neededIngredient) != availableIngredients.end()) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

