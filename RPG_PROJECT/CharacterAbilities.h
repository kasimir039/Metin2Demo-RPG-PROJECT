#pragma once
#include "Types.h"
#include <string>

enum class ABILITYTARGET {NONE,SELF,ENEMY,MULTIPLE};
enum class WEAPONEFFECT {NONE,WEAPON,UNARMED};

class CharacterAbilities
{
protected:

	std::string skillName;
	skillType attackPower;
	skillType colldown;
	skillType requiredSp;
	skillType duration;
	skillType skillLevel;
	short movingSpeed;
	skillType attackSpeed;
	skillType attackValue;
	skillType defence;
	ABILITYTARGET targetSelf;
	ABILITYTARGET targetEnemy;
	ABILITYTARGET targetMultiple;
	WEAPONEFFECT  weaponEffect;
	WEAPONEFFECT  unarmedEffect;


	CharacterAbilities(
		const std::string& sName,
		skillType cd,
		skillType sp,
		skillType atp = 0,
		skillType dur = 0,
		skillType def = 0,
		skillType aValue = 0,
		skillType aSpeed = 0,
		short mSpeed = 0,
		skillType sLevel = 1,
		ABILITYTARGET tSelf = ABILITYTARGET::NONE,
		ABILITYTARGET tEnemy = ABILITYTARGET::NONE,
		ABILITYTARGET tMultiple = ABILITYTARGET::NONE,
		WEAPONEFFECT wEffect = WEAPONEFFECT::NONE,
		WEAPONEFFECT uEffect = WEAPONEFFECT::NONE
	);
	
	CharacterAbilities() = delete;
	CharacterAbilities(const CharacterAbilities&) = delete;
	CharacterAbilities(const CharacterAbilities&&) = delete;
};

