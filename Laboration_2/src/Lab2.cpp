//------------------------------------------------------------------------------
// Lab2.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "Lab2.h"

/**
 * Main program
 */
int main() {
	
    std::cout << getAssignmentInfo() << std::endl << std::endl;

	std::cout << "Loads ingredients from _Resources/pantry.dat: \n";
	Bakery bakery("_Resources/pantry.dat");
	std::cout << "Available ingredients: ";
	for (auto &avItem : bakery.getBrm().getIngredients()) {
		std::cout << avItem << ", ";
	}
	std::cout << "\n\n";

	std::cout << "Loads BakeryRecepy's from BakingRecepyManager, should be 4 of them (Pizza, Scones, Sockerkaka, Kladdkaka): \n\n";

	for (auto &brItem : bakery.getBrm().getBrVector()) {
		std::cout << brItem->getName() << " {";
		for (auto ingredient : brItem->getNeededIng()) {
			std::cout << ingredient << ", ";
		}
		std::cout << "}\n";

		if (brItem->isBakeable(bakery.getBrm().getIngredients())) {
			std::cout << "Got all ingredients to make this?: Yes\n";
			brItem->bakeIt();
		}
		else {
			std::cout << "Can be baked?: No\n\n";
		}
	}

	std::cout << "BakingRecepy 1: " << bakery.getBrm().getBrVector().at(0)->getName() << std::endl;
	std::shared_ptr<BakingRecepy> br = bakery.getBrm().getNextBakingRecepy();
	std::cout << "call to getNextBakingRecepy(), brVector.size() should be 3: " << bakery.getBrm().getBrVector().size() << std::endl << std::endl;
	std::cout << "BakingRecepy 2: " << br->getName() << std::endl;

	br = bakery.getBrm().getNextBakingRecepy();
	std::cout << "call to getNextBakingRecepy(), brVector.size() should be 2: " << bakery.getBrm().getBrVector().size() << std::endl << std::endl;
	std::cout << "BakingRecepy 3: " << br->getName() << std::endl;
	br = bakery.getBrm().getNextBakingRecepy();
	std::cout << "call to getNextBakingRecepy(), brVector.size() should be 1: " << bakery.getBrm().getBrVector().size() << std::endl << std::endl;
	std::cout << "BakingRecepy 4: " << br->getName() << std::endl;
	try {
		std::cout << "call to getNextBakingRecepy(), should throw a noBakingException.\n";
		bakery.getBrm().getNextBakingRecepy();
	}
	catch (NoBakingException& e) {
		std::cout << "Caught a NoBakingException... Message: " << e.getMessage() << std::endl << std::endl;
	}


    return 0;
}

