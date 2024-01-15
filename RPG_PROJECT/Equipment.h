#pragma once
#include "Types.h"
#include <string>


class Equipment
{
protected:
	Equipment(std::string name);

private:
	std::string eqName;

public:

	Equipment() = delete;
	Equipment(const Equipment&) = delete;
	Equipment(const Equipment&&) = delete;


	const std::string GetEquipmentName()  const noexcept;


};

