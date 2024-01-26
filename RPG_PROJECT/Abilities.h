#pragma once

#include "CharacterAbilities.h"
#include "StatBlock.h"



class Abilities : public CharacterAbilities
{
public:
    Abilities(
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


    std::string GetSkillName() const noexcept override;
    skillType GetAttackPower()  noexcept override;
    skillType GetCooldown() const noexcept override;
    skillType GetSp() const noexcept override;
    skillType GetDuration() const noexcept override;
    skillType GetSkillLevel() const noexcept override;
    short GetMovingSpeed() const noexcept override;
    skillType GetAttackSpeed() const noexcept override;
    skillType GetAttackValue() const noexcept override;
    skillType GetDefence() const noexcept override;
    
    void SetSkillLevel(skillType lvl) override;
    void SetAttackPower(skillType atkPower) override;
    void SetAttackSpeed(skillType aSpeed) override;
    void SetMovingSpeed(skillType mSpeed) override;
    void SetAttackValue(skillType atkValue) override;
    void SetDefence(skillType def) override;

};
