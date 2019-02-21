#include "..\include\Menu.h"

//Used when the program is first started, asks the user if we should watch a 
//replay from the file "Hanoi.log" (if file is available)
bool Menu::watchReplayOrNot() {
	std::cout << "Would you want to watch a replay of the last run (based on the 'Hanoi.log' file)? Y/y to confirm: ";
	std::string input;
	getline(std::cin, input);
	if (input == "Y" || input == "y") {
		return true;
	}
	return false;
}

//Prints the menu
void Menu::printMenu() {
	std::cout << "1. Move\n";
	std::cout << "2. Undo\n";
	std::cout << "3. Redo\n";
	std::cout << "4. Reset\n";
	std::cout << "5. Show\n";
	std::cout << "6. Exit\n";
	std::cout << "Make your choice: ";
}

//Gets menuchoice between specified parameters
int Menu::getChoice(int minValue, int maxValue) {
	while (true) {
		std::string choice;
		getline(std::cin, choice);
		std::stringstream ss(choice);
		int intChoice;
		if (ss >> intChoice && intChoice >= minValue && intChoice <= maxValue) {
			return intChoice;
		}
		else {
			std::cout << "\nWrong input, try again: ";
		}
	}
}
