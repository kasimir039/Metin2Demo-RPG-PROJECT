#include "Shaman.h"

Shaman::Shaman(Player* player) : PlayerAbstraction(player),
Abilities(skillName, cooldown, requiredSp, attackPower, duration, defence, attackValue, attackSpeed, movingSpeed, skillLevel, targetSelf, targetEnemy, targetMultiple, weaponEffect, unarmedEffect),
stats(nullptr)
{
}

void Shaman::Display() const noexcept {
    std::cout << "Shaman \n";
    std::cout << "--------- \n";
}

void Shaman::ShamanDragonForceSkills()
{
    Blessing();
    DragonsRoar();
    DragonsStrength();
    FlyingTalisman();
    Reflect();
    ShootingDragon();
}

void Shaman::ShamanHealingForceSkills()
{
    AttackUp();
    Cure();
    LightningClaw();
    LightningThrow();
    SummonLightning();
    Swiftness();
}

void Shaman::Blessing()
{
    Ability.emplace_back(std::make_unique<Abilities>("Blessing", 10, 48, 0, 70, 0, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Shaman::DragonsRoar()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dragons Roar", 20, 58, 0, 0, 0, 489, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Shaman::DragonsStrength()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dragons Strength",10,48,0,65,0,0,0,0,1,ABILITYTARGET::SELF,ABILITYTARGET::NONE,ABILITYTARGET::NONE,WEAPONEFFECT::WEAPON,WEAPONEFFECT::UNARMED));
}

void Shaman::FlyingTalisman()
{
    Ability.emplace_back(std::make_unique<Abilities>("Flying Talisman", 7, 58, 0, 0, 0, 582, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Shaman::Reflect()
{
    Ability.emplace_back(std::make_unique<Abilities>("Reflect",10,48,0,70,0,0,0,0,1,ABILITYTARGET::SELF,ABILITYTARGET::NONE,ABILITYTARGET::NONE,WEAPONEFFECT::WEAPON,WEAPONEFFECT::UNARMED));

}

void Shaman::ShootingDragon()
{
    Ability.emplace_back(std::make_unique<Abilities>("Shooting Dragon",8,58,0,0,0,672,0,0,1,ABILITYTARGET::NONE,ABILITYTARGET::ENEMY,ABILITYTARGET::NONE,WEAPONEFFECT::WEAPON,WEAPONEFFECT::UNARMED ));
}

void Shaman::AttackUp()
{
}

void Shaman::Cure()
{
}

void Shaman::LightningClaw()
{
}

void Shaman::LightningThrow()
{
}

void Shaman::SummonLightning()
{
}

void Shaman::Swiftness()
{
}

void Shaman::GetBlessing() const
{
}

void Shaman::GetDragonsRoar() const
{
}

void Shaman::GetDragonsStrength() const
{
}

void Shaman::GetFlyingTalisman() const
{
}

void Shaman::GetReflect() const
{
}

void Shaman::GetShootingDragon() const
{
}

void Shaman::GetAttackUp() const
{
}

void Shaman::GetCure() const
{
}

void Shaman::GetLightningClaw() const
{
}

void Shaman::GetLightningThrow() const
{
}

void Shaman::GetSSummonLightning() const
{
}

void Shaman::Swiftness() const
{
}

void Shaman::UpgradeBlessing()
{
}

void Shaman::UpgradeDragonsRoar()
{
}

void Shaman::UpgradeDragonsStrength()
{
}

void Shaman::UpgradeFlyingTalisman()
{
}

void Shaman::UpgradeReflect()
{
}

void Shaman::UpgradeShootingDragon()
{
}

void Shaman::UpgradeAttackUp()
{
}

void Shaman::UpgradeCure()
{
}

void Shaman::UpgradeLightningClaw()
{
}

void Shaman::UpgradeLightningThrow()
{
}

void Shaman::UpgradeSummonLightning()
{
}

void Shaman::UpgradeSwiftness()
{
}
