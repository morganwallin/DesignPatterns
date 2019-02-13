#include "Vehicle.h"

std::string Vehicle::toString() {
	return "Vehicle";
}

std::string Vehicle::poweredBy() {
	return powerSource->type();
}

bool Vehicle::tryStart() {
	return powerSource->tryStart();
}

bool Vehicle::stop() {
	powerSource->stop();
	return true;
}

bool Vehicle::incPower(int p) {
	return powerSource->incPower(p);
}

bool Vehicle::decPower(int p) {
	return powerSource->decPower(p);
}

void Vehicle::setPowerSource(std::shared_ptr<PowerSource> ps) {
	powerSource = ps;
}