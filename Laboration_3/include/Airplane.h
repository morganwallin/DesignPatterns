#pragma once
#include "Vehicle.h"

//Airplane class derived from base class Vehicle, creates a Airplane with the specified powersource
class Airplane : public Vehicle
{
public:
	Airplane(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "Airplane"; };
	void drive(); //Drive airplane
private:
	void steerLeft(int degrees); // Steer airplane left with specified degrees as parameter
	void steerRight(int degrees);// Steer airplane right with specified degrees as parameter
};

