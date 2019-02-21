#pragma once
#include "Command.h"
#include "CommandManager.h"
#include "HanoiEngine.h"
#include <chrono>
#include <thread>

//Replays a previous game through reading a .log-file.
//Saves nothing to said .log-file
class Replayer {
private:
	std::ifstream is;
	std::shared_ptr<CommandManager> commandManager;
	std::shared_ptr<HanoiEngine> hanoiEngine;
public:
	Replayer(std::shared_ptr<CommandManager> pmCommandManager, std::shared_ptr<HanoiEngine> pmHanoiEngine);
	~Replayer() = default;
	void readFromFile(); //Read from file
};