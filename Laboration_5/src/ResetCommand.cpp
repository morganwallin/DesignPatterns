#include "..\include\ResetCommand.h"


ResetCommand::ResetCommand(std::shared_ptr<HanoiEngine> hanoiEngine, int pmNumberOfDiscs)
{
	_hanoiEngine = hanoiEngine;
	numberOfDiscs = pmNumberOfDiscs;
}

//Resets the game and clears the logfile
bool ResetCommand::execute() {
	_hanoiEngine->reset(numberOfDiscs);
	std::fstream file;
	file.open(fileName, std::fstream::out, std::ios::trunc);
	file.close();
	return true;
}

bool ResetCommand::unExecute() {
	return false;
}

bool ResetCommand::isUndoable() {
	return false;
}

void ResetCommand::readFromStream(std::ifstream& is) {

}