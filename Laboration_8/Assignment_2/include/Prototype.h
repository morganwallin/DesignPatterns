#pragma once

#include <iostream>
#include <string>
#include <memory>

//Base class Prototype, pure virtual, will be inherited by ConcreteComponent and ConcreteDecorators
class Prototype {
protected:
	std::string name;
	int cost;

public:
	virtual ~Prototype() = default;
	virtual std::string getName() const = 0;
	virtual int getCost() const = 0;
};

