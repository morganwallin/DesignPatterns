#pragma once
#include "Command.h"

//Derived class from the Command class. Moves a disc from one tower to another in the HanoiEngine
class MoveCommand :
	public Command
{
private:
	//Data Members
	std::shared_ptr<HanoiEngine> _hanoiEngine;
	int moveFrom, moveTo;
	bool save;

public:
	//Constructors/destructors
	MoveCommand(std::shared_ptr<HanoiEngine> hanoiEngine, int pmMoveFrom, int pmMoveTo);
	~MoveCommand() = default;

	//Data members
	virtual bool execute(); // Execute the command
	virtual bool unExecute(); // Undo the command
	virtual bool isUndoable(); // Undoable?
	virtual void readFromStream(std::ifstream&); //Read from stream
	bool executeWithoutSave(); // Executes without saving
	void saveToFile(); // Saves move to file
};

