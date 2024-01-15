#include "Armor.h"

equipmentType Armor::eqHp = 0;
equipmentType Armor::eqDef = 0;

Armor::Armor(std::string name, equipmentType hp, equipmentType def)
    :Equipment(name)
{
    eqHp = hp;
    eqDef = def;
}

<<<<<<< HEAD
const equipmentType Armor::GetArmorHp() noexcept
{
    return eqHp;
}
const equipmentType Armor::GetArmorDef() noexcept
=======
equipmentType Armor::GetArmorHp()
{
    return eqHp;
}
equipmentType Armor::GetArmorDef()
>>>>>>> ee684d823e616ca24c393e0a294fb347f7f13882
{
    return eqDef;
}