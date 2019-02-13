#pragma once
#include "Vehicle.h"
class Airplane
{
private:
	std::string vehicleType;

public:
	Airplane() { vehicleType = "Airplane"; };
	~Airplane() {};

	std::string toString() { return vehicleType; }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

