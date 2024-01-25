#pragma once
#include "PlayerAbstraction.h"
#include "Abilities.h"
#include <memory>

class Warrior final : public PlayerAbstraction,public Abilities
{
private:

    //Body
    void AuraOfTheSword();
    void Berserk();
    void Dash();
    void SwordSpin();
    void ThreeWayCut();

    //Mental
    void StrongBody();
    void SpiritStrike();
    void Bash();
    void Stump();
    void SwordStrike();

public:
    std::vector<std::unique_ptr<Abilities>> Ability;
    StatBlock* stats;

    Warrior(Player* player);

    Warrior() = delete;
    Warrior(const Warrior&) = delete;
    Warrior(const Warrior&&) = delete;

    //Function
    void Display() const noexcept override;
    void BodyWarriorSkills();
    void MentalWarriorSkills();

    //Get Skills
    void GetAuraOfTheSword() const;
    void GetBerserk() const;
    void GetDash() const;
    void GetSwordSpin() const;
    void GetThreeWayCut() const;

    void GetStrongBody() const;
    void GetSpiritStrike() const;
    void GetBash() const;
    void GetStump() const;
    void GetSwordStrike() const;


    //Upgrade Skills
    void UpgradeAuraOfTheSword();
    void UpgradeBerserk();
    void UpgradeDash();
    void UpgradeSwordSpin();
    void UpgradeThreeWayCut();



};
