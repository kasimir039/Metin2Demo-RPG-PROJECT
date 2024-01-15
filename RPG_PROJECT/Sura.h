#pragma once
#include "Player.h"
#include "PlayerAbstraction.h"



class Sura final : public PlayerAbstraction
{
public:
    Sura(Player* player);

    Sura() = delete;
    Sura(const Sura&) = delete;
    Sura(const Sura&&) = delete;

    void Display() const noexcept override;

};

