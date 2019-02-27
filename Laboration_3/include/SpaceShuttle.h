#pragma once
#include "Vehicle.h"

//SpaceShuttle class derived from base class Vehicle, creates a SpaceShuttle with the specified powersource
class SpaceShuttle : public Vehicle
{
public:
	SpaceShuttle(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "SpaceShuttle";};

	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

