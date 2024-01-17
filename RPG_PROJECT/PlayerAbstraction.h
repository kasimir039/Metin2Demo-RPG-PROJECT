#pragma once
#include "Player.h"

class PlayerAbstraction {
protected:
    Player* player;
    virtual void Display() const = 0;

public:
    PlayerAbstraction(Player* player) : player(player) {}


    virtual ~PlayerAbstraction() {};
};

