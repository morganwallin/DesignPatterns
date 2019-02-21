#include "..\include\MoveCommand.h"

MoveCommand::MoveCommand(std::shared_ptr<HanoiEngine> hanoiEngine, int pmMoveFrom, int pmMoveTo)
{
	_hanoiEngine = hanoiEngine;
	moveFrom = pmMoveFrom;
	moveTo = pmMoveTo;
	save = false;
}

//Tries to move discs between specified positions, and saves the move to file if successful
bool MoveCommand::execute() {
	if (_hanoiEngine->move(moveFrom, moveTo)) {
		saveToFile();
		return true;
	}
	return false;
}

//Tries to move discs between specified positions
bool MoveCommand::executeWithoutSave() {
	if (_hanoiEngine->move(moveFrom, moveTo)) {
		return true;
	}
	return false;
}

//Undo the previous command if possible
bool MoveCommand::unExecute() {
	if (_hanoiEngine->move(moveTo, moveFrom)) { //reverse moveTo/moveFrom
		int tmp = moveTo;
		moveTo = moveFrom;
		moveFrom = tmp;
		saveToFile();
		tmp = moveTo;
		moveTo = moveFrom;
		moveFrom = tmp;
		return true;
	}
	return false;
}

bool MoveCommand::isUndoable() {
	return true;
}

void MoveCommand::readFromStream(std::ifstream& is) {
	if (!is.is_open()) {
		std::cout << "Error in filestream";
		return;
	}
	is >> moveFrom >> moveTo;
}

//Save command to file. Create file if non-existant.
void MoveCommand::saveToFile() {
	std::ofstream file(fileName, std::fstream::out | std::ios::app);
	if (!file.is_open()) {
		file.open(fileName, std::fstream::out, std::ios::trunc);
	}
	file << "Move " << moveFrom << " " << moveTo << "\n";
	file.close();
}