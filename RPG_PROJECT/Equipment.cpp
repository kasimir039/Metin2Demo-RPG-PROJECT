#include "Equipment.h"

Equipment::Equipment(const std::string& name) 
	: eqName(name)
{
}

  std::string Equipment::GetEquipmentName() const noexcept { return eqName; }






