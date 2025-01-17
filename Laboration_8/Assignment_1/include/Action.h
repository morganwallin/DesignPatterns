//------------------------------------------------------------------------------
// Action.h DT063G Design Patterns With C++
// Action to be performed by the player
//------------------------------------------------------------------------------

#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using std::ostream;
using std::string;
using std::cout;
using std::endl;

//Action class, base class for all the different classes that will be available for the player
class Action {
protected:
    string typeStr;
    string description;

public:
    Action(string type, string desc) : typeStr(type), description(desc) {}
    virtual ~Action()= default;
    const string& operator()(void) { return typeStr; }
    const string& show() {return description;}
    virtual bool doIt(Player*, ostream &os) = 0;
};


class ChainsawAction : public Action {
public:
    ChainsawAction()
            :Action("ChainsawAction","Use your chainsaw\n"){ }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You are aggressivly using your chainsaw..." << endl;
            player->decResources();
        }
        else {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};


class SwordAction : public Action {
public:
    SwordAction()
            :Action("SwordAction","Use your sword\n") { }

    bool doIt(Player *player, ostream &os) override {
        os << "You are using your long sharp sword..." << endl;
        player->decHealth();
        return true;
    }
};


class RifleAction : public Action {
public:
    RifleAction()
            :Action("RifleAction","Use your rifle\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getAmmo()) {
            os << "You are shooting with your rifle..." << endl;
            player->decAmmo();
        }
        else  {
            os << "Sorry. You're out of ammunition." << endl;
            return false;
        }
        return true;
    }
};

class BargainAndBuyAction : public Action {
public:
    BargainAndBuyAction()
            :Action("BargainAndBuyAction","Negotiate and offer money\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You are trying to talk and buy yourself out of it..." << endl;
            player->decResources();
        }
        else  {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};

class BowAndShakeHandsAction : public Action {
public:
    BowAndShakeHandsAction()
            :Action("BowAndShakeHandsAction","Bow politely and try to shake hands\n")
    { }

    bool doIt(Player *player, ostream &os) override {
        os << "You are politely bowing and shaking hands..." << endl;
        return true;
    }

};

class RunAndHideAction : public Action {
public:
    RunAndHideAction()
            :Action("RunAndHideAction","Run and try to hide\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You think running and hiding will save you..." << endl;
            player->decResources();
        }
        else  {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};


class CastAspellAction : public Action {
public:
    CastAspellAction()
            :Action("CastAspellAction","Try to cast a spell\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You are trying to cast a spell..." << endl;
            player->decResources();
        }
        else {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};


class ClimbAction : public Action {
public:
    ClimbAction()
            :Action("ClimbAction","Try to climb\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You are trying to climb the obstacle..." << endl;
            player->decResources();
        }
        else {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};


class OfferFoodAction : public Action {
public:
    OfferFoodAction()
            :Action("OfferFoodAction","Offer some food\n") { }

    bool doIt(Player *player, ostream &os) override {
        if(player->getResources()) {
            os << "You are offering some deliciuos food..." << endl;
            player->decResources();
        }
        else {
            os << "Sorry. You're out of resources." << endl;
            return false;
        }
        return true;
    }
};

class SurrenderAction : public Action {
public:
    SurrenderAction()
            :Action("SurrenderAction","I surrender!\n") { }

    bool doIt(Player *player, ostream &os) override {
        player->kill();
        return false;
    }
};