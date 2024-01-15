#pragma once
#include "Player.h"
#include "PlayerAbstraction.h"
#include "Player.h"



class Assassin final : public PlayerAbstraction
{
public:
    Assassin(Player* player);

    Assassin() = delete;
    Assassin(const Assassin&) = delete;
    Assassin(const Assassin&&) = delete;

    void Display() const noexcept override;

};

