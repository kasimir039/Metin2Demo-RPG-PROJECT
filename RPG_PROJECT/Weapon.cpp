#include "Weapon.h"

equipmentType Weapon::eqAttackPower = 0;

Weapon::Weapon(std::string name, equipmentType attack) 
	: Equipment(name)
{
	eqAttackPower = attack;
}

equipmentType Weapon::GetWeaponPower()  { return Weapon::eqAttackPower; }


