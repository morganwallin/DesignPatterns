#include "Sockerkaka.h"



Sockerkaka::Sockerkaka() : BakingRecepy("Sockerkaka")
{
	neededIng = { Ingredient("egg"), Ingredient("sugar"), Ingredient("baking-powder"), Ingredient("wheat-flour"), Ingredient("marge"), Ingredient("lemon") };
}

void Sockerkaka::bakeIt() {
	std::cout << "How to bake Sockerkaka: \n";
	std::cout << "1. Preheat oven to 175 degrees.\n";
	std::cout << "2. Mix the ingredients.\n";
	std::cout << "3. Put the dough in a sockerkaksform.\n";
	std::cout << "4. Bake in oven for 45 minutes.\n\n\n";
}