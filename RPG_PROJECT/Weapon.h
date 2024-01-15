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


	static equipmentType GetWeaponPower();

};

