//------------------------------------------------------------------------------
// Game.cpp DT063G Design Patterns With C++
// Implementation of Game
//------------------------------------------------------------------------------

#include <iostream>
#include "Game.h"

using std::cin;

template<typename T>
void destroyVectorElements(vector<T> &vec);

//Create object
Game::Game(GameFactory *gFact) {
	title = "Morgans Game";
	obstacles = gFact->makeObstacles();
	actions = gFact->makeActions();
	player = gFact->makePlayer();
}

//Destroy pointers
Game::~Game() {
    destroyVectorElements(obstacles);
    destroyVectorElements(actions);
    delete player;
}

//Game simulation, lets player play the game
void Game::play( ) {

    cout << "*** Welcome to " << title << " ***" << endl;

    typedef std::vector<Action*>::iterator AtypeIt;
    typedef std::vector<Obstacle*>::iterator OtypeIt;

    AtypeIt aStart=actions.begin(), aStop=actions.end(), ait;
    OtypeIt oStart=obstacles.begin(), oStop=obstacles.end(), oit;

    for(oit=oStart; oit!=oStop&& player->alive(); ++oit) {

        int alt, choice;
        bool passed = false;

        while(!passed && player->alive()) {
            (*oit)-> show();
            cout <<"\nChoose action:\n";

            for(alt=1, ait=aStart; ait!=aStop&& player->alive();++alt,++ait)
                cout << "\t " << alt << ' '<< (*ait)->show();

            while(!(cin >> choice) || choice <1 || choice >=alt) {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            passed = (*oit)->tryToPass(player,actions[choice-1]);
            player->show();
        }   // while
    }
    if(player->alive())
        cout << "\nYou Win!" << endl;
    else
        cout << "\nYou Lose!" << endl;
    cin.ignore(cin.rdbuf()->in_avail());
}


template<typename T>
void destroyVectorElements(vector<T> &vec) {
	for (std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		delete (*it);
	}
	vec.clear();
}