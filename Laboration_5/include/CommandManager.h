#pragma once

#include <memory>
#include "Command.h"
#include "MoveCommand.h"
#include "ShowCommand.h"
#include "ResetCommand.h"
#include <list>

// CommandManager is the Command Invoker. Takes commands from the command issuer (Client)
// and sends the to the command reciever (HanoiEngine). Stores 2 lists for
// undoing/redoing
class CommandManager
{
private:
	//Data members
	typedef std::list<std::shared_ptr<Command>> CommandList;
	CommandList undoList;
	CommandList redoList;
	int undoLevel;

	//Private functions
	std::shared_ptr<Command> popUndo();
	std::shared_ptr<Command> popRedo();
	void clear();
	void clearCommandList(CommandList pList);
	void addUndo(std::shared_ptr<Command> pCommand);
	void addRedo(std::shared_ptr<Command> pCommand);


public:
	//Constructors/Destructors
	CommandManager(int nUndoLevel = 100);
	~CommandManager();

	//Public functions
	bool doCommand(std::shared_ptr<Command> command);
	bool canUndo() const;
	bool canRedo() const;
	bool undo();
	bool redo();
	void clearUndoList();
	void clearRedoList();
	int getUndoLevel() const;
	void setUndoLevel(int newValue);
};

