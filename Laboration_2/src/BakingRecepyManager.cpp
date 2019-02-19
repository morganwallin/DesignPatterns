#include "BakingRecepyManager.h"


BakingRecepyManager::BakingRecepyManager(std::string fileName)
{
	std::shared_ptr<Pizza> pizza;
	pizza.reset(new Pizza());
	std::shared_ptr<Scones> scones;
	scones.reset(new Scones());
	std::shared_ptr<Sockerkaka> sockerkaka;
	sockerkaka.reset(new Sockerkaka());
	std::shared_ptr<Kladdkaka> kladdkaka;
	kladdkaka.reset(new Kladdkaka());
	bakingRecepies = { std::move(pizza), std::move(scones), std::move(sockerkaka), std::move(kladdkaka)};

	std::ifstream infile(fileName);
	if (!infile.is_open()) {
		std::cout << "unable to open file" << std::endl;
	}


	std::string line;
	while (getline(infile, line)) {
		availableIngredients.push_back(Ingredient(line));
	}

	infile.close();
}

bool BakingRecepyManager::hasAnotherRecepy() {
	if (bakingRecepies.size() >= 1) {
		return true;
	}
	else {
		return false;
	}
}

std::shared_ptr<BakingRecepy> BakingRecepyManager::getNextBakingRecepy() {
	if (hasAnotherRecepy()) {
		auto bakingRecepy = bakingRecepies.at(0);
		bakingRecepies.erase(bakingRecepies.begin());
		return bakingRecepy;
	}
	else {
		throw NoBakingException("No more recepies available.");
		exit(1);
	}
	
	
}
