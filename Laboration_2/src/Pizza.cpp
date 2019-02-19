#include "Pizza.h"



Pizza::Pizza() : BakingRecepy("Pizza")
{
	neededIngredients = { Ingredient("oil"), Ingredient("yeast"), Ingredient("wheat-flour"), Ingredient("salt"), Ingredient("tomato-sauce") };
}


void Pizza::bakeIt() {
	std::cout << "How to make Pizza: \n";
	std::cout << "1. Preheat oven to 250 degrees.\n";
	std::cout << "2. Mix the ingredients into a dough.\n";
	std::cout << "3. Roll the dough until thin.\n";
	std::cout << "4. Add toppings (optional).\n";
	std::cout << "5. Bake in oven for 10-12 minutes.\n\n\n";
}