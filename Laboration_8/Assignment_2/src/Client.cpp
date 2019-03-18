#include "Client.h"

Client::Client()
{
	menu = std::make_shared<Menu>();
	beverage = nullptr;
}

//Client simulation, creates menu and lets user play
void Client::run() {
	do {
		//Print menu and get user choice
		menu->printBeverageMenu();
		int menuChoice = menu->getChoice();

		beverage = nullptr;
		//Create beverage depending on user choice
		switch (menuChoice) {
			case 1:
			{
				beverage = PrototypeManager::instance().getDrink("Coffee");
				break;
			}
			case 2:
			{
				beverage = PrototypeManager::instance().getDrink("Espresso");
				break;
			}
			case 3:
			{
				beverage = PrototypeManager::instance().getDrink("Tea");
				break;
			}
			case 4:
			{
				beverage = PrototypeManager::instance().getDrink("Chocolate");
				break;
			}
			case 5:
			{
				return;
			}
		}//end of switch



		do {//While-loop to choose extras
			menu->printExtrasMenu();
			menuChoice = menu->getChoice(1, 6);
			
			// Adds an extra to the beverage, updates name and cost
			switch (menuChoice) {
				case 1:
				{
					beverage = PrototypeManager::instance().getDecorator(beverage, "Sugar");
					break;
				}
				case 2:
				{
					beverage = PrototypeManager::instance().getDecorator(beverage, "Milk");
					break;
				}
				case 3:
				{
					beverage = PrototypeManager::instance().getDecorator(beverage, "Cream");
					break;
				}
				case 4:
				{
					beverage = PrototypeManager::instance().getDecorator(beverage, "Whipped Cream");
					break;
				}
				case 5:
				{
					break;
				}
				case 6:
				{
					return;
				}
			}//end of switch

		} while (menuChoice != 5); // Extras do-while loop
		std::cout << "Your order: " << beverage->getName() << ". Cost: " << beverage->getCost() << "kr.\n\n";
	} while (menu->goAgain()); //Beverage/outer-while
}

