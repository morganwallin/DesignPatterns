#pragma once

#include <string>
#include "PowerSource.h"
#include "PowerSourceAdapters.h"
#include <iostream>
#include <memory>
#include <string>

//Base class Vehicle
class Vehicle {
public:
	Vehicle() = default;
	
	virtual ~Vehicle() = default;
	virtual std::string toString() { return vehicleType; } // e.g."SpaceShutte"
	virtual std::string poweredBy(); // e.g."FuelCell"
	
	virtual void drive() = 0; // Simulate a driving scenario
	virtual void setPowerSource(std::shared_ptr<PowerSource> ps); // Change PowerSource

	
	
	//Optional driving operations of your choice
	//...
protected:
	explicit Vehicle(std::shared_ptr<PowerSource> ps) { powerSource = ps; }
	std::shared_ptr<PowerSource> powerSource;
	std::string vehicleType;
	virtual bool tryStart(); // Try to start the powersource
	virtual bool stop(); // Stop the powersource
	virtual bool incPower(int p = 5); // Increase power
	virtual bool decPower(int p = 5); // Decrease power
									  //Operations for steering
	virtual void steerLeft(int degrees) = 0; //Steer left
	virtual void steerRight(int degrees) = 0; //Steer right 
};