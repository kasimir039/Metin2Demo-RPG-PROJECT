#include "Assassin.h"


Assassin::Assassin(Player* player) : PlayerAbstraction(player)
{
}

void Assassin::Display() const noexcept {
    std::cout << "Assassin \n";
    std::cout << "--------- \n";
}