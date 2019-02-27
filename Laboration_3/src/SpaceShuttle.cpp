#include "SpaceShuttle.h"

//Drives spaceshuttle
void SpaceShuttle::drive() {
	std::cout << "Trying to start engine with power 0:\n";
	tryStart();

	std::cout << "\nIncrease power to 100 and try to start engine:\n";
	incPower(100);
	tryStart();

	std::cout << "\nSpaceShuttle is on it's way \n";

	steerLeft(10);
	steerRight(10);


	std::cout << "\nStopping the vehicle: \n";
	if (stop()) {
		std::cout << "PowerSource turned off successfully.\n";
	}
	else {
		std::cout << "Failed to turn off PowerSource";
	}
}

//Steers spaceshuttle left
void SpaceShuttle::steerLeft(int degrees) {
	std::cout << "SpaceShuttle steers " << degrees << " degrees to the left.\n";
}

//Steers spaceshuttle right
void SpaceShuttle::steerRight(int degrees) {
	std::cout << "SpaceShuttle steers " << degrees << " degrees to the right.\n";
}