#include "Warrior.h"


Warrior::Warrior(Player* player) : PlayerAbstraction(player)
{
}

void Warrior::Display() const noexcept {
    std::cout << "Warrior \n";
    std::cout << "--------- \n";
}