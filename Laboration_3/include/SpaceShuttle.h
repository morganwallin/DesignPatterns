#pragma once
#include "Vehicle.h"

class SpaceShuttle
{
private:
	std::string vehicleType;

public:
	SpaceShuttle() { vehicleType = "SpaceShuttle"; };
	~SpaceShuttle() {};

	std::string toString() { return vehicleType; }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

