#pragma once
#include "PlayerAbstraction.h"
#include "Abilities.h"
#include <memory>


class Sura final : public PlayerAbstraction,public Abilities
{
private:
    //Black Magic
    void DarkOrb();
    void DarkProtection();
    void DarkStrike();
    void FlameSpirit();
    void FlameStrike();
    void SpiritStrike();

    //Mental
    void Dispel();
    void DragonSwirl();
    void EnchantedArmour();
    void EnchantedBlade();
    void Fear();
    void FingerStrike();

    StatBlock* stats;

public:

    Sura(Player* player);

    Sura() = delete;
    Sura(const Sura&) = delete;
    Sura(const Sura&&) = delete;

    std::vector<std::unique_ptr<Abilities>> Ability;

    //Function
    void Display() const noexcept override;
    void SuraBlackMagicSkills();
    void SuraWeaponarySkills();

    //Get Skills
    void GetDarkOrb() const;
    void GetDarkProtection() const;
    void GetDarkStrike() const;
    void GetFlameSpirit() const;
    void GetFlameStrike() const;
    void GetSpiritStrike() const;

    void GetDispel() const;
    void GetDragonSwirl() const;
    void GetEnchantedArmour() const;
    void GetEnchtantedBlade() const;
    void GetFear() const;
    void GetFingerStrike() const;

    //Upgrade Skills
    void UpgradeDarkOrb();
    void UpgradeDarkProtection();
    void UpgradeDarkStrike();
    void UpgradeFlameSpirit();
    void UpgradeFlameStrike();
    void UpgradeSpiritStrike();

    void UpgradeDispel();
    void UpgradeDragonSwirl();
    void UpgradeEnchantedArmour();
    void UpgradeEnchtantedBlade();
    void UpgradeFear();
    void UpgradeFingerStrike();

};

