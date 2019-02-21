#include "..\include\ShowCommand.h"



ShowCommand::ShowCommand(std::shared_ptr<HanoiEngine> hanoiEngine)
{
	_hanoiEngine = hanoiEngine;
}


bool ShowCommand::execute() {
	_hanoiEngine->show();
	return true;
}

bool ShowCommand::unExecute() {
	return false;
}

bool ShowCommand::isUndoable() {
	return false;
}

void ShowCommand::readFromStream(std::ifstream& is) {

}