#include "..\include\Replayer.h"

Replayer::Replayer(std::shared_ptr<CommandManager> pmCommandManager, std::shared_ptr<HanoiEngine> pmHanoiEngine) {
	commandManager = pmCommandManager;
	hanoiEngine = pmHanoiEngine;
}

//Read from file and replay the commands
void Replayer::readFromFile() {
	std::string line;
	is.open("Hanoi.log");

	if (is.is_open() && is.peek() != EOF) {
		hanoiEngine->show(); //Show hanoi tower
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Wait 1 second
		while (is.peek() != EOF) {
			getline(is, line, ' '); //Get first word (Currently only 'Move' supported
			if (line == "Move") {
				std::shared_ptr<MoveCommand> moveCommand = std::make_shared<MoveCommand>(hanoiEngine, 0, 0); //Initialize MoveCommand
				moveCommand->readFromStream(is); //Get the moveFrom/moveTo ints from file
				moveCommand->executeWithoutSave(); //Execute command
			}
			getline(is, line); //Remove newline from stream
			hanoiEngine->show();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	else {
		std::cout << "Could not open and read Hanoi.log\n\n";
		return;
	}
	std::cout << "*** REPLAY OVER *** \n\n\n";
	is.close();
}