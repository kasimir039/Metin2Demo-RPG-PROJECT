#pragma once
#include "Player.h"
#include "PlayerAbstraction.h"


class Assassin final : public PlayerAbstraction
{
public:
    explicit Assassin(Player* player);

    Assassin() = delete;

    void Display() const noexcept override;

};

