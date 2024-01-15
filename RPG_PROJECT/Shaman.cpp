#include "Shaman.h"

Shaman::Shaman(Player* player) : PlayerAbstraction(player)
{
}

void Shaman::Display() const noexcept {
    std::cout << "Shaman \n";
    std::cout << "--------- \n";
}