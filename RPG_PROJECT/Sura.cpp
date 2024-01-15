#include "Sura.h"

Sura::Sura(Player* player) : PlayerAbstraction(player)
{
}


void Sura::Display() const noexcept {
    std::cout << "Sura \n";
    std::cout << "--------- \n";
}