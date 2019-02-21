#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "Command.h"
#include "MoveCommand.h"


//Prints and navigates through the menu
class Menu
{
public:
	//Constructors/Destructors
	Menu() = default;
	~Menu() = default;

	//Member Functions
	void printMenu();
	bool watchReplayOrNot();
	int getChoice(int = 1, int = 6);
};

