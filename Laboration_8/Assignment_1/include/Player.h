//------------------------------------------------------------------------------
// Player.h DT063G Design Patterns With C++
//------------------------------------------------------------------------------

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;

//Player base class, resources, ammo, health and type is managed here
class Player {
private:
    string typeStr;
    int resources, ammo, health;
public:
    Player(string type, int r, int a, int h)
            : typeStr(type), resources(r), ammo(a), health(h) { }
    void decResources() { --resources; }
    void incResources() { ++resources; }
    int getResources() const { return resources; }
    void decAmmo() { --ammo; }
    int getAmmo() const { return ammo; }
    void decHealth() { --health; }
    int getHealth() const { return health; }
    void kill() { health=0; }
    bool alive() const { return health >0; }
    void show(ostream &os=cout);
};

//Ordinary player, derived from base class Player
class OrdinaryPlayer : public Player {
public:
    OrdinaryPlayer( )
            :Player("OrdinaryPlayer",5,3,3) { }
};

//HeroPlayer, derived from base class Player
class HeroPlayer : public Player {
public:
    HeroPlayer( )
            :Player("HeroPlayer",7,5,5) { }
};