#pragma once
#include "Vehicle.h"

//Submarine class derived from base class Vehicle, creates a Submarine with the specified powersource
class Submarine : public Vehicle
{
public:
	Submarine(std::shared_ptr<PowerSource> ps) : Vehicle(ps) { vehicleType = "Submarine"; };
	void drive(); //Drive Submarine
private:
	void steerLeft(int degrees); // Steer Submarine left with specified degrees as parameter
	void steerRight(int degrees);// Steer Submarine right with specified degrees as parameter
};

