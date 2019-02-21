#pragma once
#include <fstream>
#include "HanoiEngine.h"
#include <memory>
#include <iostream>
#include <string>
#include <sstream>

//Base class
class Command {
protected:
	//Data members
	std::string fileName = "Hanoi.log"; //Filename where we will save/load commands
public:
	virtual bool execute() = 0; // Execute the command
	virtual bool unExecute() = 0; // Undo the command
	virtual bool isUndoable() = 0; // Undoable?
	virtual void readFromStream(std::ifstream&) = 0; //Read from stream
	virtual ~Command() = default;
};