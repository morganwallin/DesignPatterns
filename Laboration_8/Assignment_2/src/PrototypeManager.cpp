#include "..\include\PrototypeManager.h"

PrototypeManager::PrototypeManager() {
	costs.insert(std::make_pair<std::string, int>("Coffee", 10));
	costs.insert(std::make_pair<std::string, int>("Espresso", 14));
	costs.insert(std::make_pair<std::string, int>("Tea", 10));
	costs.insert(std::make_pair<std::string, int>("Chocolate", 12));
	costs.insert(std::make_pair<std::string, int>("Sugar", 1));
	costs.insert(std::make_pair<std::string, int>("Milk", 1));
	costs.insert(std::make_pair<std::string, int>("Cream", 2));
	costs.insert(std::make_pair<std::string, int>("Whipped Cream", 5));
}

PrototypeManager& PrototypeManager::instance() {
	static PrototypeManager instance;
	return instance;
}

std::shared_ptr<Prototype> PrototypeManager::getDrink(std::string drinkName) {
	std::shared_ptr<DrinkPrototype> drink;
	drink = drink->clone();
	drink->initialize(costs[drinkName], drinkName); 
	return drink; 
}

std::shared_ptr<Prototype> PrototypeManager::getDecorator(std::shared_ptr<Prototype> comp, std::string decoratorName) {
	std::shared_ptr<DecoratorPrototype> decorator;
	decorator = decorator->clone(comp);
	//decorator = std::dynamic_pointer_cast<DecoratorPrototype>(decorator->clone(comp));
	decorator->initialize(costs[decoratorName], decoratorName, comp);
	return decorator;
}