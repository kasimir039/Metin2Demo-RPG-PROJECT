#pragma once
#include "ShamanSkills.h"
#include "Abilities.h"

class ShamanHealingForceSkills : public Abilities {
private:
    void AttackUp();
    void Cure();
    void LightningClaw();
    void LightningThrow();
    void SummonLightning();
    void Swiftness();

    void Display() const noexcept;

public:
    void GetAttackUp() const;
    void GetCure() const;
    void GetLightningClaw() const;
    void GetLightningThrow() const;
    void GetSummonLightning() const;
    void GetSwiftness() const;

    void UpgradeAttackUp();
    void UpgradeCure();
    void UpgradeLightningClaw();
    void UpgradeLightningThrow();
    void UpgradeSummonLightning();
    void UpgradeSwiftness();

    ShamanHealingForceSkills() = default;
};