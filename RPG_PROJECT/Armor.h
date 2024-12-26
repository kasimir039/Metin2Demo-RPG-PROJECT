#include "Equipment.h"

class Armor final : public Equipment
{
private:

	static equipmentType eqHp;
	static equipmentType eqDef;

public:

	Armor(std::string name, equipmentType hp, equipmentType defense);
	Armor() = delete;


	static  equipmentType GetArmorHp() noexcept;
	static  equipmentType GetArmorDef() noexcept;


};