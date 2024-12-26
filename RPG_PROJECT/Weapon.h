#pragma once
#include "Equipment.h"

class Weapon final :  public Equipment
{
private:
	
	static equipmentType eqAttackPower;

public:

	Weapon(const std::string& name,equipmentType attack);
	Weapon() = delete;

	static equipmentType GetWeaponPower() noexcept;


};

