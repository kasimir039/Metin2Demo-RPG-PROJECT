#include "Armor.h"

equipmentType Armor::eqHp = 0;
equipmentType Armor::eqDef = 0;

Armor::Armor(std::string name, equipmentType hp, equipmentType def)
    :Equipment(name)
{
    eqHp = hp;
    eqDef = def;
}


const equipmentType Armor::GetArmorHp() noexcept
{
    return eqHp;
}
const equipmentType Armor::GetArmorDef() noexcept
{
    return eqDef;
}