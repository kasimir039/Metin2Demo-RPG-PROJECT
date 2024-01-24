#include "CharacterAbilities.h"

CharacterAbilities::CharacterAbilities(
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
    : skillName(sName),
    colldown(cd),
    requiredSp(sp),
    attackPower(atp),
    duration(dur),
    defence(def),
    attackValue(aValue),
    attackSpeed(aSpeed),
    movingSpeed(mSpeed),
    skillLevel(sLevel),
    targetSelf(tSelf),
    targetEnemy(tEnemy),
    targetMultiple(tMultiple),
    weaponEffect(wEffect),
    unarmedEffect(uEffect)
{
}



