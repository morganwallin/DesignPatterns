//------------------------------------------------------------------------------
// GameFactory.h DT063G Design Patterns With C++
// GameFactory is an abstract class which defines an interface for
// derived concrete classes
//------------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include "Player.h"

using std::vector;
using std::string;

class Player;
class Obstacle;
class Action;

//Game factory, to be used in "Game"-class. Creates different settings depending on which type of Factory it will be
class GameFactory {
protected:
    GameFactory() { }

public:
    virtual ~GameFactory() = default;
	virtual vector<Obstacle*> makeObstacles()=0;
	virtual vector<Action*> makeActions()=0;
	virtual Player* makePlayer()=0;
};

class NastyGameFactory : public GameFactory {
public:
	vector<Obstacle*> makeObstacles();
	vector<Action*> makeActions();
	Player* makePlayer() { return new HeroPlayer(); }
};

class NiceGameFactory : public GameFactory {
public:
	vector<Obstacle*> makeObstacles();
	vector<Action*> makeActions();
	Player* makePlayer() { return new OrdinaryPlayer(); }
};
