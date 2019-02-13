#include "VehicleAdapters.h"
#include "Airplane.h"
#include "Submarine.h"
#include "SpaceShuttle.h"

//Airplane
void AirplaneAD::drive() {
	airplane.drive();
}

void AirplaneAD::steerLeft(int degrees) {
	airplane.steerLeft(degrees);
}

void AirplaneAD::steerRight(int degrees) {
	airplane.steerRight(degrees);
}

//Submarine
void SubmarineAD::drive() {
	submarine.drive();
}

void SubmarineAD::steerLeft(int degrees) {
	submarine.steerLeft(degrees);
}

void SubmarineAD::steerRight(int degrees) {
	submarine.steerRight(degrees);
}

//SpaceShuttle
void SpaceShuttleAD::drive() {
	spaceShuttle.drive();
}

void SpaceShuttleAD::steerLeft(int degrees) {
	spaceShuttle.steerLeft(degrees);
}

void SpaceShuttleAD::steerRight(int degrees) {
	spaceShuttle.steerRight(degrees);
}