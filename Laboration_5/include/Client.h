#pragma once

#include "Menu.h"
#include "HanoiEngine.h"
#include "CommandManager.h"
#include <memory>
#include "Replayer.h"

//Client is the command issuer. Uses:
//Menu-object to navigate and print the menu
//HanoiEngine-object to use as game engine
//CommandManager to recieve commands from Client and send them to HanoiEngine
//Replayer to read and replay a previous game from file
class Client
{
private:
	//Data members
	std::shared_ptr<Menu> menu; //Menu-object
	std::shared_ptr<HanoiEngine> hanoiEngine; //Game engine
	std::shared_ptr<CommandManager> commandManager; //Command invoker
	std::shared_ptr<Replayer> replayer; //Replayer

public:
	//Constructor/Destructor
	Client();
	~Client() = default;

	//Functions
	void run(); //Simulation
	void getMoves(int &moveFrom, int &moveTo);
	void show();
	void move(int moveFrom, int moveTo);
	int getNumberOfDiscs();
	int validateInput(int min, int max);
	
};

