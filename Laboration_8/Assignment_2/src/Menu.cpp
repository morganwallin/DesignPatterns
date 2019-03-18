#include "..\include\Menu.h"


//Prints the menu
bool Menu::goAgain() const {
	std::cout << "Would you like to order another beverage? (Y/y to confirm): ";
	std::string userInput;
	getline(std::cin, userInput);
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	if (userInput == "y" || userInput == "yes") {
		return true;
	}
	return false;
}

// Print extras menu
void Menu::printExtrasMenu() const {
	std::cout << "\n1. Sugar (1:-)\n";
	std::cout << "2. Milk (1:-)\n";
	std::cout << "3. Cream (2:-)\n";
	std::cout << "4. Whipped Cream (5:-)\n";
	std::cout << "5. No more extras\n";
	std::cout << "6. Exit\n";
	std::cout << "Choice: ";
}

// Print beverage menu
void Menu::printBeverageMenu() const {
	std::cout << "\n1. Coffee (10:-)\n";
	std::cout << "2. Espresso (14:-)\n";
	std::cout << "3. Tea (10:-)\n";
	std::cout << "4. Chocolate (12:-)\n";
	std::cout << "5. Exit\n";
	std::cout << "Choice: ";
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


