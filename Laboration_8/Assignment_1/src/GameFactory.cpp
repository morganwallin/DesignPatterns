//------------------------------------------------------------------------------
// GameFactory.cpp DT063G Design Patterns With C++
// Implementations of concrete factory classes
//------------------------------------------------------------------------------

#include "GameFactory.h"
#include "Obstacle.h"
#include "Action.h"

/** Implementations of concrete factory classes */
NastyGameFactory& NastyGameFactory::instance() {
	static NastyGameFactory instance;
	return instance;
}

vector<Obstacle*> NastyGameFactory::makeObstacles() {
	vector<Obstacle*> obs;
	obs.push_back(new Dragon());
	obs.push_back(new Bomb());
	obs.push_back(new Samuray());
	obs.push_back(new SumoWrestler());
	obs.push_back(new Gangster());
	return obs;
}


vector<Action*> NastyGameFactory::makeActions() {
	vector<Action*> act;
	act.push_back(new BowAndShakeHandsAction());
	act.push_back(new RunAndHideAction());
	act.push_back(new SwordAction());
	act.push_back(new RifleAction());
	act.push_back(new OfferFoodAction());
	act.push_back(new ChainsawAction());
	act.push_back(new CastAspellAction());
	act.push_back(new BargainAndBuyAction());
	act.push_back(new SurrenderAction());
	return act;

}


NiceGameFactory& NiceGameFactory::instance() {
	static NiceGameFactory instance;
	return instance;
}

vector<Obstacle*> NiceGameFactory::makeObstacles() {
	vector<Obstacle*> obs;
	obs.push_back(new Wizard());
	obs.push_back(new Wall());
	obs.push_back(new Elephant());
	obs.push_back(new DPexam());
	return obs;
}

vector<Action*> NiceGameFactory::makeActions() {
	vector<Action*> act;
	act.push_back(new BowAndShakeHandsAction());
	act.push_back(new RunAndHideAction());
	act.push_back(new BargainAndBuyAction());
	act.push_back(new ChainsawAction());
	act.push_back(new ClimbAction());
	act.push_back(new CastAspellAction());
	act.push_back(new SurrenderAction());
	return act;
}