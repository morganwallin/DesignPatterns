#pragma once
#include "Vehicle.h"

//Submarine class derived from base class Vehicle, creates a Submarine with the specified powersource
class Submarine : public Vehicle
{
public:
	Submarine(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "Submarine"; };

	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

