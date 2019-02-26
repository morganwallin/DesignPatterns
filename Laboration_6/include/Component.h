#pragma once

#include <iostream>
#include <string>

//Base class Component, pure virtual, will be inherited by ConcreteComponent and ConcreteDecorators
class Component {
protected:
	std::string name;
	int cost;

public:
	virtual ~Component() = default;
	virtual std::string getName() const = 0;
	virtual int getCost() const = 0;
};

