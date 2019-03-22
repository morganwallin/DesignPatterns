#include "..\include\Client.h"

//Runs the program
void Client::run() {

	int choice;
	bool keepOn = true;

	GameFactory *gf = nullptr;
	
	while (keepOn) {
		
		cout << "Choose your game:" << endl;
		cout << "1 - Nice game" << endl;
		cout << "2 - Nasty game" << endl;
		cout << "3 - quit" << endl;

		while (!(std::cin >> choice) || choice <1 || choice >3) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		}

		switch (choice) {
		case 1:  gf = &NiceGameFactory::instance(); break;
		case 2:  gf = &NastyGameFactory::instance(); break;
		case 3: keepOn = false;
		default: break;
		}

		if (keepOn) {
			Game game(gf);
			game.play();
			
		}
	} // while
	delete gf;
}
