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
skillType Abilities::GetAttackPower() noexcept{ return attackPower; }
skillType Abilities::GetCooldown() const noexcept{ return cooldown; }
skillType Abilities::GetSp() noexcept{ return requiredSp; }
skillType Abilities::GetDuration() noexcept{ return duration; }
skillType Abilities::GetSkillLevel() noexcept{ return skillLevel; }
short Abilities::GetMovingSpeed() noexcept{ return movingSpeed; }
skillType Abilities::GetAttackSpeed() noexcept{ return attackSpeed; }
skillType Abilities::GetAttackValue() noexcept{ return attackValue; }
skillType Abilities::GetDefence() noexcept{ return defence; }

void Abilities::SetSkillLevel(skillType lvl)
{
    skillLevel += lvl;
}

void Abilities::SetAttackPower(skillType atkPower)
{
    attackPower += atkPower;
}

void Abilities::SetAttackSpeed(skillType aSpeed)
{
    attackSpeed += aSpeed;
}

void Abilities::SetMovingSpeed(skillType mSpeed)
{
    movingSpeed += mSpeed;
}

void Abilities::SetAttackValue(skillType atkValue)
{
    attackValue += atkValue;
}

void Abilities::SetDefence(skillType def)
{
    defence += def;
}
