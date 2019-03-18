#pragma once

#include "ConcreteComponent.h"
#include "ConcreteDecorators.h"
#include <memory>
#include <map>
class PrototypeManager
{
private:
	std::map<std::string, int> costs;
public:
	static PrototypeManager& instance();
	std::shared_ptr<Prototype> getDrink(std::string drinkName);
	std::shared_ptr<Prototype> getDecorator(std::shared_ptr<Prototype> comp, std::string decoratorName);
	PrototypeManager();
	~PrototypeManager() {}
};

