#include "Weapon.h"

equipmentType Weapon::eqAttackPower = 0;

Weapon::Weapon(const std::string& name, equipmentType attack) 
	: Equipment(name)
{
	eqAttackPower = attack;
}

 equipmentType Weapon::GetWeaponPower() noexcept { return Weapon::eqAttackPower; }



