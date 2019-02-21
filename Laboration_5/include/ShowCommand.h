#pragma once
#include "Command.h"

//Derived from Command class. ShowCommand is used to show the current state of the game.
class ShowCommand :
	public Command
{
private:
	std::shared_ptr<HanoiEngine> _hanoiEngine;
public:
	ShowCommand(std::shared_ptr<HanoiEngine> hanoiEngine);
	~ShowCommand() = default;
	virtual bool execute(); // Execute the command
	virtual bool unExecute(); // Undo the command
	virtual bool isUndoable(); // Undoable?
	virtual void readFromStream(std::ifstream&); //Read from stream
};

