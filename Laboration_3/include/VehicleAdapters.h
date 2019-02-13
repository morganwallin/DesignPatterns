#pragma once

#include "Vehicle.h"
#include "SpaceShuttle.h"
#include "Airplane.h"
#include "Submarine.h"

class SubmarineAD : public Vehicle
{
private:
	Submarine submarine;

public:
	SubmarineAD() {};
	SubmarineAD(std::shared_ptr<PowerSource> ps) : Vehicle(ps) {};
	~SubmarineAD() {};

	std::string toString() { return submarine.toString(); }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

class AirplaneAD : public Vehicle
{
private:
	Airplane airplane;

public:
	AirplaneAD() {};
	AirplaneAD(std::shared_ptr<PowerSource> ps) : Vehicle(ps) {};
	~AirplaneAD() {};

	std::string toString() { return airplane.toString(); }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

class SpaceShuttleAD : public Vehicle
{
private:
	SpaceShuttle spaceShuttle;

public:
	SpaceShuttleAD() {};
	SpaceShuttleAD(std::shared_ptr<PowerSource> ps) : Vehicle(ps) {};
	~SpaceShuttleAD() {};

	std::string toString() { return spaceShuttle.toString(); }
	void drive();
	void steerLeft(int degrees);
	void steerRight(int degrees);
};

