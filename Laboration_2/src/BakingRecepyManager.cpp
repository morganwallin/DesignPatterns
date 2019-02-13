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
	brVector = { std::move(pizza), std::move(scones), std::move(sockerkaka), std::move(kladdkaka)};

	std::ifstream infile(fileName);
	if (!infile.is_open()) {
		std::cout << "unable to open file" << std::endl;
	}


	std::string line;
	while (getline(infile, line)) {
		availableIngredient.push_back(Ingredient(line));
	}

	infile.close();
}

BakingRecepyManager::~BakingRecepyManager()
{
	
}

bool BakingRecepyManager::hasAnotherRecepy() {
	if (brVector.size() > 1) {
		return false;
	}
	else {
		return true;
	}
}

std::shared_ptr<BakingRecepy> BakingRecepyManager::getNextBakingRecepy() {
	try {
		brVector.erase(brVector.begin());
		return brVector.at(0);
	}
	catch (std::exception& e) {
		throw NoBakingException("No more recepies available.");
		exit(1);
	}
	
}
