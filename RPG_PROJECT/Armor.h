#include "Equipment.h"

class Armor final : public Equipment
{
private:

	static equipmentType eqHp;
	static equipmentType eqDef;

public:

	Armor(std::string name, equipmentType hp, equipmentType defense);
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;


<<<<<<< HEAD
	static const equipmentType GetArmorHp() noexcept;
	static const equipmentType GetArmorDef() noexcept;
=======
	static equipmentType GetArmorHp();
	static equipmentType GetArmorDef();
>>>>>>> ee684d823e616ca24c393e0a294fb347f7f13882

};