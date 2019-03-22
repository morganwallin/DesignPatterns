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
	GameFactory() = default;
public:
	virtual ~GameFactory() = default;
	virtual vector<Obstacle*> makeObstacles()=0;
	virtual vector<Action*> makeActions()=0;
	virtual Player* makePlayer()=0;
};

//Concrete classes created as Singletons
class NastyGameFactory : public GameFactory {
private:
	NastyGameFactory() {}
public:
	static NastyGameFactory& instance();
	vector<Obstacle*> makeObstacles();
	vector<Action*> makeActions();
	Player* makePlayer() { return new HeroPlayer(); }
	NastyGameFactory(NastyGameFactory const&) = delete;
	void operator=(NastyGameFactory const&) = delete;
};

class NiceGameFactory : public GameFactory {
private:
	NiceGameFactory() {}
public:
	static NiceGameFactory& instance();
	vector<Obstacle*> makeObstacles();
	vector<Action*> makeActions();
	Player* makePlayer() { return new OrdinaryPlayer(); }
	NiceGameFactory(NiceGameFactory const&) = delete;
	void operator=(NiceGameFactory const&) = delete;
};
