#include "..\include\Client.h"

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
				beverage = std::make_shared<Coffee>();
				break;
			}
			case 2:
			{
				beverage = std::make_shared<Espresso>();
				break;
			}
			case 3:
			{
				beverage = std::make_shared<Tea>();
				break;
			}
			case 4:
			{
				beverage = std::make_shared<Chocolate>();
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
					beverage = std::make_shared<Sugar>(beverage);
					break;
				}
				case 2:
				{
					beverage = std::make_shared<Milk>(beverage);
					break;
				}
				case 3:
				{
					beverage = std::make_shared<Cream>(beverage);
					break;
				}
				case 4:
				{
					beverage = std::make_shared<WhippedCream>(beverage);
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

