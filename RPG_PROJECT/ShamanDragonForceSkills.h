#pragma once
#include "ShamanSkills.h"
#include "Abilities.h"

class ShamanDragonForceSkills : public Abilities {
private:
    void Blessing();
    void DragonsRoar();
    void DragonsStrength();
    void FlyingTalisman();
    void Reflect();
    void ShootingDragon();

    void Display() const noexcept;

public:
    void GetBlessing() const;
    void GetDragonsRoar() const;
    void GetDragonsStrength() const;
    void GetFlyingTalisman() const;
    void GetReflect() const;
    void GetShootingDragon() const;

    void UpgradeBlessing();
    void UpgradeDragonsRoar();
    void UpgradeDragonsStrength();
    void UpgradeFlyingTalisman();
    void UpgradeReflect();
    void UpgradeShootingDragon();
};
