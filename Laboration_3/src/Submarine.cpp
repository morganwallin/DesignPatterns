#include "Submarine.h"


void Submarine::drive() {
	std::cout << "Trying to start engine with power 0:\n";
	tryStart();

	std::cout << "\nIncrease power to 100 and try to start engine:\n";
	incPower(100);
	tryStart();

	std::cout << "\nSubmarine is going down the depths \n";

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

void Submarine::steerLeft(int degrees) {
	std::cout << "Submarine steers " << degrees << " degrees to the left.\n";
}

void Submarine::steerRight(int degrees) {
	std::cout << "Submarine steers " << degrees << " degrees to the left.\n";
}