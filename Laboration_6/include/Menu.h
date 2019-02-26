#pragma once

#include <iostream>
#include <string>
#include <sstream>


//Prints and navigates through the menu
class Menu
{
public:
	//Constructors/Destructors
	Menu() = default;
	~Menu() = default;

	//Member Functions
	bool goAgain() const; // Ask user if he wanna order another beverage
	void printExtrasMenu() const; // Print menu for extras
	void printBeverageMenu() const; //Print menu for beverages
	int getChoice(int minValue = 1, int maxValue = 5); //Gets choice from user, checks so it returns an int between
};

