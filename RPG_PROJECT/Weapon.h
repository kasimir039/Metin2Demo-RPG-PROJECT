#pragma once
#include "Equipment.h"

class Weapon final :  public Equipment
{
private:
	
	static equipmentType eqAttackPower;

public:

	Weapon(std::string name,equipmentType attack);
	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;


<<<<<<< HEAD
	static const equipmentType GetWeaponPower() noexcept;
=======
	static equipmentType GetWeaponPower();
>>>>>>> ee684d823e616ca24c393e0a294fb347f7f13882

};

