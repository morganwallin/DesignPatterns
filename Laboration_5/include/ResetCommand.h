#pragma once
#include "Command.h"


//Derived from Command class. ResetCommand is used to reset the game.
//Also clears the logfile
class ResetCommand :
	public Command
{
	private:
		std::shared_ptr<HanoiEngine> _hanoiEngine;
		int numberOfDiscs;
	public:
		ResetCommand(std::shared_ptr<HanoiEngine> hanoiEngine, int pmNumberOfDiscs);
		~ResetCommand() = default;
		virtual bool execute(); // Execute the command
		virtual bool unExecute(); // Undo the command
		virtual bool isUndoable(); // Undoable?
		virtual void readFromStream(std::ifstream&); //Read from stream
	};

