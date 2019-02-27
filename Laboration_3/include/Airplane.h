#pragma once
#include "Vehicle.h"

//Airplane class derived from base class Vehicle, creates a Airplane with the specified powersource
class Airplane : public Vehicle
{
public:
	Airplane(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "Airplane"; };

	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

