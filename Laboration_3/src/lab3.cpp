//------------------------------------------------------------------------------
// Lab3.cpp DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#include "Lab3.h"
#include "PowerSourceAdapters.h"
#include "VehicleAdapters.h"

#include <sstream>
#include <iostream>
#include "memstat.hpp"


/**
 * Main program
 */

int main() {
	std::string input;
	int vehicleChoice, engineChoice;

	std::cout << "Available Vehicles\n";
	std::cout << "1. SpaceShuttle\n";
	std::cout << "2. Submarine\n";
	std::cout << "3. Airplane\n\n";
	std::cout << "Make your choice: ";
	while (true) {
		getline(std::cin, input);
		std::stringstream ss(input);
		if (ss >> vehicleChoice && vehicleChoice > 0 && vehicleChoice <= 3) {
			break;
		}
		std::cout << "Invalid input, please try again: \n";
	}

	std::cout << "Available Engines\n";
	std::cout << "1. V8 Classic\n";
	std::cout << "2. Fuel cell\n";
	std::cout << "3. Gas turbine\n\n";
	std::cout << "Make your choice: ";
	while (true) {
		getline(std::cin, input);
		std::stringstream ss(input);
		if (ss >> engineChoice && engineChoice > 0 && engineChoice <=3) {
			break;
		}
		std::cout << "Invalid input, please try again: \n";
	}

	std::shared_ptr<PowerSource> engine;
	switch (engineChoice) {
	case 1:
		engine = std::make_shared<V8ClassicAD>();
		break;
	case 2:
		engine = std::make_shared<FuelCellAD>();
		break;
	case 3:
		engine = std::make_shared<GasTurbineAD>();
		break;
	}


	std::shared_ptr<Vehicle> vehicle;
	switch (vehicleChoice) {
	case 1:
		vehicle = std::make_shared<SpaceShuttleAD>(engine);
		break;
	case 2:
		vehicle = std::make_shared<SubmarineAD>(engine);
		break;
	case 3:
		vehicle = std::make_shared<AirplaneAD>(engine);
		break;

	}
	
	std::cout << "\n" << getAssignmentInfo() << "\n\n";
	std::cout << "You created a " << vehicle->toString() << " with a " << vehicle->poweredBy() << " as a power source.\n";
	std::cout << "Trying to start engine with power 0:\n";
	vehicle->tryStart();

	std::cout << "\nIncrease power to 100 and try to start engine:\n";
	vehicle->incPower(100);
	vehicle->tryStart();

	std::cout << "\nDrive the vehicle:\n";
	vehicle->drive();
	
	std::cout << "\nSteer right and left 10 degrees:\n";
	vehicle->steerLeft(10);
	vehicle->steerRight(10);

	std::cout << "\nChange the power source:\n";
	std::cout << "Engine you chose: " << vehicle->poweredBy() << std::endl;
	vehicle->setPowerSource(std::make_shared<V8ClassicAD>());
	std::cout << "Engine after we changed it: " << vehicle->poweredBy() << std::endl;
	vehicle->setPowerSource(std::make_shared<FuelCellAD>());
	std::cout << "Engine after we changed it again: " << vehicle->poweredBy() << std::endl;

	std::cout << "\nStop the vehicle: \n";
	vehicle->stop();

    return 0;
}