#include "Weapon.h"

equipmentType Weapon::eqAttackPower = 0;

Weapon::Weapon(std::string name, equipmentType attack) 
	: Equipment(name)
{
	eqAttackPower = attack;
}

<<<<<<< HEAD
const equipmentType Weapon::GetWeaponPower() noexcept { return Weapon::eqAttackPower; }
=======
equipmentType Weapon::GetWeaponPower()  { return Weapon::eqAttackPower; }
>>>>>>> ee684d823e616ca24c393e0a294fb347f7f13882


