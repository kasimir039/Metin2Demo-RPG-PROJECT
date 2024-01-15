#include "Weapon.h"

equipmentType Weapon::eqAttackPower = 0;

Weapon::Weapon(std::string name, equipmentType attack) 
	: Equipment(name)
{
	eqAttackPower = attack;
}

const equipmentType Weapon::GetWeaponPower() noexcept { return Weapon::eqAttackPower; }



