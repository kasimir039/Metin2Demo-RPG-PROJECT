#include "Warrior.h"


Warrior::Warrior(Player* player) : PlayerAbstraction(player)
{

}


void Warrior::Display() const noexcept {
    std::cout << "Warrior \n";
    std::cout << "--------- \n";
}

void Warrior::bodyWarriorSkills()
{
    
    //name,colldown,sp,attack power,duration,defence,attack value,attack speed,moving speed,skill level,target self,target enemy,target multiple,weapon effect,unarmed effect
    Abilities.emplace_back("Aura of the Sword", 35, 110, 25, 32, 0, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON); // Strength (++)
    Abilities.emplace_back("Berserk", 67, 57, 0, 64, 0, 0, 2, 1, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON,WEAPONEFFECT::UNARMED); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Dash", 12, 66, 0, 0, 0, 0, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Sword Spin", 15, 56, 0, 0, 0, 1226, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Three-Way Cut",12,45,0,0,0,1336,0,0,1,ABILITYTARGET::NONE,ABILITYTARGET::ENEMY,ABILITYTARGET::MULTIPLE,WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::mentalWarriorSkills()
{
    Abilities.emplace_back("Strong Body", 67, 91, 0, 64, 13, 0, 0, -1, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED); // Vitality (++), Strength (+)
    Abilities.emplace_back("Spirit Strike", 15, 66, 0, 0, 0, 997, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Bash", 15, 67, 0, 0, 0, 987, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Stump", 25, 57, 0, 0, 0, 855, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED); // Strength (++), Dexterity (+), Vitality (0/+)
    Abilities.emplace_back("Sword Strike", 20, 46, 0, 0, 0, 840, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON); // Strength (++), Dexterity (+), Vitality (0/+)
}
