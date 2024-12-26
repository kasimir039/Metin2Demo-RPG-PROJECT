#pragma once
#include "PlayerAbstraction.h"
#include "Abilities.h"
#include <memory>

enum class SHAMAN_SKILLS { BLESSING = 1, DRARGONS_ROAR, DRAGONS_STRENGTH, FLYING_TALISMAN, REFLECT, SHOOTING_DRAGON, ATTACK_UP, CURE, LIGHTNING_CLAW, LIGHTNING_THROW, SUMMON_LIGHTNING, SWIFTNESS };
enum class CHOOSE_SHAMAN_SKILLS { DARGON_FORCE = 1, HEALING_FORCE };

class Shaman final : public PlayerAbstraction,public Abilities
{
private:
    //Dragon Force
    void Blessing();
    void DragonsRoar();
    void DragonsStrength();
    void FlyingTalisman();
    void Reflect();
    void ShootingDragon();

    //Healing Force
    void AttackUp();
    void Cure();
    void LightningClaw();
    void LightningThrow();
    void SummonLightning();
    void Swiftness();

    StatBlock* stats;
public:
    explicit Shaman(Player* player);

    Shaman() = delete;

    std::vector<std::unique_ptr<Abilities>> Ability;

    //Function
    void Display() const noexcept override;
    void ShamanDragonForceSkills();
    void ShamanHealingForceSkills();

    //Get Skills
    void GetBlessing() const;
    void GetDragonsRoar() const;
    void GetDragonsStrength() const;
    void GetFlyingTalisman() const;
    void GetReflect() const;
    void GetShootingDragon() const;

    void GetAttackUp() const;
    void GetCure() const;
    void GetLightningClaw() const;
    void GetLightningThrow() const;
    void GetSummonLightning() const;
    void GetSwiftness() const;

    //Upgrade Skills
    void UpgradeBlessing();
    void UpgradeDragonsRoar();
    void UpgradeDragonsStrength();
    void UpgradeFlyingTalisman();
    void UpgradeReflect();
    void UpgradeShootingDragon();

    void UpgradeAttackUp();
    void UpgradeCure();
    void UpgradeLightningClaw();
    void UpgradeLightningThrow();
    void UpgradeSummonLightning();
    void UpgradeSwiftness();

};

