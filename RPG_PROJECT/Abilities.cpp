#include "Abilities.h"

Abilities::Abilities(
    const std::string& sName,
    skillType cd,
    skillType sp,
    skillType atp,
    skillType dur,
    skillType def,
    skillType aValue,
    skillType aSpeed,
    short mSpeed,
    skillType sLevel,
    ABILITYTARGET tSelf,
    ABILITYTARGET tEnemy,
    ABILITYTARGET tMultiple,
    WEAPONEFFECT wEffect,
    WEAPONEFFECT uEffect
)
    : CharacterAbilities(sName, cd, sp, atp, dur, def, aValue, aSpeed, mSpeed, sLevel, tSelf, tEnemy, tMultiple, wEffect, uEffect)
{
}

std::string Abilities::GetSkillName() const noexcept{ return skillName; }
skillType Abilities::GetAttackPower()  noexcept{ return attackPower; }
skillType Abilities::GetCooldown() const noexcept{ return cooldown; }
skillType Abilities::GetSp() const noexcept{ return requiredSp; }
skillType Abilities::GetDuration() const noexcept{ return duration; }
skillType Abilities::GetSkillLevel() const noexcept{ return skillLevel; }
short Abilities::GetMovingSpeed() const noexcept{ return movingSpeed; }
skillType Abilities::GetAttackSpeed() const noexcept{ return attackSpeed; }
skillType Abilities::GetAttackValue() const noexcept{ return attackValue; }
skillType Abilities::GetDefence() const noexcept{ return defence; }

void Abilities::SetSkillLevel(skillType lvl)
{
    skillLevel += lvl;
}

void Abilities::SetAttackPower(skillType atk)
{
    attackPower = atk;
}
