#include "..\include\Client.h"

Client::Client()
{
	hanoiEngine = std::make_shared<HanoiEngine>();
	menu = std::make_shared<Menu>();
	commandManager = std::make_shared<CommandManager>();
	replayer = std::make_shared<Replayer>(commandManager, hanoiEngine);
}

//Client simulation, creates menu and lets user play
void Client::run() {
	if (menu->watchReplayOrNot()) {
		replayer->readFromFile();
	}
	while (true) {
		//Show hanoi tower
		show();

		//Print menu and get user choice
		menu->printMenu();
		int menuChoice = menu->getChoice();

		//Issue commands depending on user choice, uses commandManager to issue command
		switch (menuChoice) {
			case 1:
			{
				int moveFrom, moveTo; 
				getMoves(moveFrom, moveTo); //asks user from and where to move a disc
				move(moveFrom, moveTo); //creates MoveCommand and calls commandManager->doCommand()
				break;
			}
			case 2:
			{
				commandManager->undo(); break;
			}
			case 3:
			{
				commandManager->redo(); break;
			}
			case 4: 
			{
				commandManager->doCommand(std::make_shared<ResetCommand>(hanoiEngine, getNumberOfDiscs())); break; //Reset
			}
			case 5:
			{
				show(); break; //Show HanoiTower
			}
			case 6:
			{
				return;
			}
		}

	}
}

//Checks to see if input is an int between parameters min and max
int Client::validateInput(int min, int max) {
	while (true) {
		std::string choice;
		getline(std::cin, choice);
		std::stringstream ss(choice);
		int intChoice;
		if (ss >> intChoice && intChoice >= min && intChoice <= max) {
			return intChoice;
		}
		else {
			std::cout << "Wrong input, try again: ";
		}
	}
}

//Gets disc-move from player and validates input
void Client::getMoves(int &moveFrom, int &moveTo) {

	std::cout << "From: ";
	moveFrom = validateInput(1, 3);
	std::cout << "To: ";
	moveTo = validateInput(1, 3);
}

int Client::getNumberOfDiscs() {
	std::cout << "Reset game with how many number of discs?: ";
	return validateInput(1, 99);
}

void Client::show() {
	std::shared_ptr<ShowCommand> showCommand = std::make_shared<ShowCommand>(hanoiEngine);
	commandManager->doCommand(showCommand);
}

void Client::move(int moveFrom, int moveTo) {
	std::shared_ptr<MoveCommand> moveCommand = std::make_shared<MoveCommand>(hanoiEngine, moveFrom, moveTo);
	commandManager->doCommand(moveCommand);
}