#include "Equipment.h"

Equipment::Equipment(std::string name) 
	: eqName(name)
{
}

const std::string Equipment::GetEquipmentName() const noexcept { return eqName; }






