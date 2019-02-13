#pragma once
#include "Vehicle.h"
class Submarine
{
private:
	std::string vehicleType;
public:
	Submarine() { vehicleType = "Submarine"; };
	~Submarine() {};

	std::string toString() { return vehicleType; }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

