#include "Kladdkaka.h"



Kladdkaka::Kladdkaka() : BakingRecepy("Kladdkaka")
{
	neededIng = { Ingredient("egg"), Ingredient("sugar"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("salt"), Ingredient("marge"), Ingredient("cocoa-powder") };
}

void Kladdkaka::bakeIt() {
	std::cout << "How to bake Kladdkaka: \n";
	std::cout << "1. Preheat oven to 175 degrees.\n";
	std::cout << "2. Mix the ingredients.\n";
	std::cout << "3. Put in ovenware.\n";
	std::cout << "4. Bake in oven for 15 minutes.\n\n\n";
}