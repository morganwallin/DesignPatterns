#include "BakingRecepy.h"



BakingRecepy::BakingRecepy(std::string aName)
{
	name = aName;
}

BakingRecepy::BakingRecepy() {
	name = typeid(this).name();
}

bool BakingRecepy::isBakeable(std::vector<Ingredient>& availableIng) {
	for(auto &nIng : neededIng) {
		if (std::find(availableIng.begin(), availableIng.end(), nIng) != availableIng.end()) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

