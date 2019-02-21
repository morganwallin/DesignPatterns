#include "..\include\CommandManager.h"

CommandManager::CommandManager(int nUndoLevel) : undoLevel(nUndoLevel) {}

CommandManager::~CommandManager() {
	clear();
}

bool CommandManager::canUndo() const {
	return (!undoList.empty());
}

bool CommandManager::canRedo() const {
	return (!redoList.empty());
}

int CommandManager::getUndoLevel() const {
	return undoLevel;
}

void CommandManager::setUndoLevel(int newValue) {
	undoLevel = newValue;
}

std::shared_ptr<Command> CommandManager::popUndo() {
	std::shared_ptr<Command> pCommand = undoList.back();
	undoList.pop_back();
	return pCommand;
}

std::shared_ptr<Command> CommandManager::popRedo() {
	std::shared_ptr<Command> pCommand = redoList.back();
	redoList.pop_back();
	return pCommand;
}

bool CommandManager::doCommand(std::shared_ptr<Command> pCommand) {
	// Execute the command.
	// Add to undo list if successful and undoable
	if (pCommand->execute() && pCommand->isUndoable()) {
		addUndo(pCommand);
		// A new command clears RedoList
		clearRedoList();
		return true;
	}
	return false;
}

bool CommandManager::undo() {
	if (canUndo()) {
		std::shared_ptr<Command> pCommand = popUndo();
		if (pCommand->unExecute())
			addRedo(pCommand);
		return true;
	}
	std::cout << "Couldn't undo...\n";
	return false;
}

bool CommandManager::redo() {
	if (canRedo()) {
		std::shared_ptr<Command> pCommand = popRedo();
		if (pCommand->execute())
			addUndo(pCommand);
		
		return true;
	}
	std::cout << "Couldn't redo...\n";
	return false;
}

void CommandManager::clear() {
	clearUndoList();
	clearRedoList();
}

void CommandManager::addUndo(std::shared_ptr<Command> pCommand) {
	undoList.push_back(pCommand);
}

void CommandManager::addRedo(std::shared_ptr<Command> pCommand) {
	redoList.push_back(pCommand);
}

void CommandManager::clearUndoList() {
	clearCommandList(undoList);
}

void CommandManager::clearRedoList() {
	clearCommandList(redoList);
}

void CommandManager::clearCommandList(CommandList pList) {
	pList.erase(pList.begin(), pList.end());
}