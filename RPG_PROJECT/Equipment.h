#pragma once
#include "Types.h"
#include <string>


class Equipment
{
protected:
	explicit Equipment(const std::string& name);

private:
	std::string eqName;

public:

	Equipment() = delete;



	  std::string GetEquipmentName() const noexcept;


};

