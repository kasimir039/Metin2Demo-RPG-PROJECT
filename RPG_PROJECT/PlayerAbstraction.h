#pragma once
#include "Player.h"
#include "CharacterAbilities.h"
#include "vector"

class PlayerAbstraction {
protected:
    Player* player;
    std::vector<CharacterAbilities> Abilities;
    virtual void Display() const = 0;

public:
    PlayerAbstraction(Player* player) : player(player) {}


    virtual ~PlayerAbstraction() {};
};

