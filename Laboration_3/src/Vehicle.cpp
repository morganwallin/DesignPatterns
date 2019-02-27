#include "Vehicle.h"

//Returns vehicles powersource
std::string Vehicle::poweredBy() {
	return powerSource->type();
}

//Tries to start powersource
bool Vehicle::tryStart() {
	return powerSource->tryStart();
}

//Stops the powersource
bool Vehicle::stop() {
	powerSource->stop();
	return powerSource->isRunning();
}

//Increases the powersource with the int specified as parameter
bool Vehicle::incPower(int p) {
	return powerSource->incPower(p);
}

//Decreases the powersource with the int specified as parameter
bool Vehicle::decPower(int p) {
	return powerSource->decPower(p);
}

//Changes the vehicles powersource
void Vehicle::setPowerSource(std::shared_ptr<PowerSource> ps) {
	powerSource = ps;
}