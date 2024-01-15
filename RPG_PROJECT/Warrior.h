#pragma once
#include "Player.h"
#include "PlayerAbstraction.h"





class Warrior final : public PlayerAbstraction
{
public:
    Warrior(Player* player);

    Warrior() = delete;
    Warrior(const Warrior&) = delete;
    Warrior(const Warrior&&) = delete;

    void Display() const noexcept override;

};

