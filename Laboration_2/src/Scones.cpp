#include "Scones.h"



Scones::Scones() : BakingRecepy("Scones")
{
	neededIng = { Ingredient("oil"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("salt"), Ingredient("sugar"), Ingredient("milk") };
}

void Scones::bakeIt() {
	std::cout << "How to bake Scones: \n";
	std::cout << "1. Preheat oven to 225 degrees.\n";
	std::cout << "2. Mix the ingredients.\n";
	std::cout << "3. Split the dough into smaller pieces.\n";
	std::cout << "4. Bake in oven for 15 minutes.\n\n\n";
}