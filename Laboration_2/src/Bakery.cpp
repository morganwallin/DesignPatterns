#include "Bakery.h"



Bakery::Bakery() : bakingRecepyManager("_Resources/pantry.dat"){
}


void Bakery::runBakery() {
	while (true) {
		try {
			auto bakingRecepy = bakingRecepyManager.getNextBakingRecepy();
			bakingRecepy->bakeIt();
		}
		catch (NoBakingException& e) {
			std::cout << "Caught a NoBakingException... Message: " << e.getMessage() << std::endl << std::endl;
			break;
		}
	}
}
