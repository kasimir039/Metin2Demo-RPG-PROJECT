#include "Armor.h"

equipmentType Armor::eqHp = 0;
equipmentType Armor::eqDef = 0;

Armor::Armor(std::string name, equipmentType hp, equipmentType def)
    :Equipment(name)
{
    eqHp = hp;
    eqDef = def;
}

equipmentType Armor::GetArmorHp()
{
    return eqHp;
}
equipmentType Armor::GetArmorDef()
{
    return eqDef;
}