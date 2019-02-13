#pragma once

#include <string>
#include "PowerSource.h"
#include <iostream>
#include <memory>

class Vehicle {
public:
	Vehicle() {};
	Vehicle(std::shared_ptr<PowerSource> ps) { powerSource = ps; }
	virtual ~Vehicle() {};
	virtual std::string toString(); // e.g."SpaceShutte"
	std::string poweredBy(); // e.g."FuelCell"
	bool tryStart(); // Try to start the powersource
	bool stop(); // Stop the powersource
	bool incPower(int p = 5); // Increase power
	bool decPower(int p = 5); // Decrease power
	virtual void drive() = 0; // Simulate a driving scenario
	void setPowerSource(std::shared_ptr<PowerSource> ps); // Change PowerSource

									   //Operations for steering
	virtual void steerLeft(int degrees) = 0;
	virtual void steerRight(int degrees) = 0;
	
	//Optional driving operations of your choice
	//...
private:
	std::shared_ptr<PowerSource> powerSource;
};