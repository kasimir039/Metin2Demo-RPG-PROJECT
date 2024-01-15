#pragma once
#include "Player.h"
#include "PlayerAbstraction.h"



class Shaman final : public PlayerAbstraction
{
public:
    Shaman(Player* player);

    Shaman() = delete;
    Shaman(const Shaman&) = delete;
    Shaman(const Shaman&&) = delete;

    void Display() const noexcept override;

};

