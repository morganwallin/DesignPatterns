#pragma once
#include "Vehicle.h"

//SpaceShuttle class derived from base class Vehicle, creates a SpaceShuttle with the specified powersource
class SpaceShuttle : public Vehicle
{
public:
	SpaceShuttle(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "SpaceShuttle";};
	void drive(); //Drive SpaceShuttle
private:
	void steerLeft(int degrees); // Steer SpaceShuttle left with specified degrees as parameter
	void steerRight(int degrees);// Steer SpaceShuttle right with specified degrees as parameter
};

