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
	skillType cooldown;
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

public:

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

	virtual std::string GetSkillName() const noexcept = 0;
	virtual skillType GetAttackPower()  noexcept  = 0;
	virtual skillType GetCooldown() const noexcept  = 0;
	virtual skillType GetSp() const noexcept = 0;
	virtual skillType GetDuration() const noexcept = 0;
	virtual skillType GetSkillLevel() const noexcept = 0;
	virtual short GetMovingSpeed() const noexcept = 0;
	virtual skillType GetAttackSpeed() const noexcept = 0;
	virtual skillType GetAttackValue() const noexcept = 0;
	virtual skillType GetDefence() const noexcept = 0;

	virtual void SetSkillLevel(skillType lvl) = 0;
	virtual void SetAttackPower(skillType atkPower) = 0;
	virtual void SetAttackSpeed(skillType aSpeed) = 0;
	virtual void SetMovingSpeed(skillType mSpeed) = 0;
	virtual void SetAttackValue(skillType atkValue) = 0;
	virtual void SetDefence(skillType def) = 0;



	CharacterAbilities() = delete;
	virtual ~CharacterAbilities() = default;

};

