#include "Bakery.h"



Bakery::Bakery() : bakingRecepyManager("_Resources/pantry.dat"){
}


void Bakery::runBakery() {
	std::cout << "Available ingredients: ";
	for (auto &availableItem : bakingRecepyManager.getIngredients()) {
		std::cout << availableItem << ", ";
	}

	std::cout << "\n\nLoads BakeryRecepy's from BakingRecepyManager, should be 4 of them (Pizza, Scones, Sockerkaka, Kladdkaka): \n\n";
	for (auto &recepyItem : bakingRecepyManager.getBakingRecepies()) {
		std::cout << recepyItem->getName() << " {";
		for (auto ingredient : recepyItem->getNeededIng()) {
			std::cout << ingredient << ", ";
		}
		std::cout << "}\nCan be baked?: ";


		if (recepyItem->isBakeable(bakingRecepyManager.getIngredients())) {
			std::cout << "Yes\n";
			recepyItem->bakeIt();
		}
		else {
			std::cout << "No\n\n\n";
		}
	}
	try {
	std::shared_ptr<BakingRecepy> bakingRecepy = bakingRecepyManager.getNextBakingRecepy();
	std::cout << "BakingRecepy 1: " << bakingRecepy->getName() << std::endl;
	bakingRecepy = getBakingRecepyManager().getNextBakingRecepy();
	std::cout << "BakingRecepy 2: " << bakingRecepy->getName() << std::endl;
	bakingRecepy = getBakingRecepyManager().getNextBakingRecepy();
	std::cout << "BakingRecepy 3: " << bakingRecepy->getName() << std::endl;
	bakingRecepy = getBakingRecepyManager().getNextBakingRecepy();
	std::cout << "BakingRecepy 4: " << bakingRecepy->getName() << std::endl;
	std::cout << "call to getNextBakingRecepy(), should throw a noBakingException.\n";
	bakingRecepyManager.getNextBakingRecepy();
	}
	catch (NoBakingException& e) {
		std::cout << "Caught a NoBakingException... Message: " << e.getMessage() << std::endl << std::endl;
	}
}