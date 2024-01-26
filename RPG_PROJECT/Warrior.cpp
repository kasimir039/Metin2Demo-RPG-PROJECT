#include "Warrior.h"


Warrior::Warrior(Player* player) : PlayerAbstraction(player),
Abilities(skillName, cooldown, requiredSp, attackPower, duration, defence, attackValue, attackSpeed, movingSpeed, skillLevel, targetSelf, targetEnemy, targetMultiple, weaponEffect, unarmedEffect),
stats(nullptr)

{

}

void Warrior::Display() const noexcept {
    std::cout << "Warrior \n";
    std::cout << "--------- \n";
}


void Warrior::BodyWarriorSkills()
{
    AuraOfTheSword();
    Berserk();
    Dash();
    SwordSpin();
    ThreeWayCut();
}

void Warrior::MentalWarriorSkills()
{
    StrongBody();
    SpiritStrike();
    Bash();
    Stump();
    SwordStrike();
}

void Warrior::AuraOfTheSword()
{
    Ability.emplace_back(std::make_unique<Abilities>("Aura of the Sword", 35, 110, 25, 32, 0, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON)); // Strength (++)
}

void Warrior::Berserk()
{
    Ability.emplace_back(std::make_unique<Abilities>("Berserk", 67, 57, 0, 64, 0, 0, 2, 1, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::Dash()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dash", 12, 66, 0, 0, 0, 0, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::SwordSpin()
{
    Ability.emplace_back(std::make_unique<Abilities>("Sword Spin", 15, 56, 0, 0, 0, 1226, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::ThreeWayCut()
{
    Ability.emplace_back(std::make_unique<Abilities>("Three-Way Cut", 12, 45, 0, 0, 0, 1336, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::StrongBody()
{
    Ability.emplace_back(std::make_unique<Abilities>("Strong Body", 67, 91, 0, 64, 13, 0, 0, -1, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED)); // Vitality (++), Strength (+)
}

void Warrior::SpiritStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Spirit Strike", 15, 66, 0, 0, 0, 997, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::Bash()
{
    Ability.emplace_back(std::make_unique<Abilities>("Bash", 15, 67, 0, 0, 0, 987, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::Stump()
{
    Ability.emplace_back(std::make_unique<Abilities>("Stump", 25, 57, 0, 0, 0, 855, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::SwordStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Sword Strike", 20, 46, 0, 0, 0, 840, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON)); // Strength (++), Dexterity (+), Vitality (0/+)
}

void Warrior::GetAuraOfTheSword() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Aura of the Sword")
        {

            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Power: " << ability->GetAttackPower() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetBerserk() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Berserk")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Speed: " << ability->GetAttackSpeed() << "\n";
            std::cout << "Moving Speed: " << ability->GetMovingSpeed() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetDash() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dash")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetSwordSpin() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Sword Spin")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetThreeWayCut() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Three-Way Cut")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetStrongBody() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Strong Body")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Defence: " << ability->GetDefence() << "\n";
            std::cout << "Moving Speed: " << ability->GetMovingSpeed() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetSpiritStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Spirit Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetBash() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Bash")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetStump() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Stump")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::GetSwordStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Sword Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Warrior::UpgradeAuraOfTheSword()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Aura Of The Sword") {
            auto attackPower =  GetAttackPower() + 5;
            SetAttackPower(attackPower);
            SetSkillLevel(1);
        }
    }

}

void Warrior::UpgradeBerserk()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Berserk") {
            auto attackSpeed = GetAttackSpeed() + 1;
            auto movingSpeed = GetMovingSpeed() + 1;
            SetAttackSpeed(attackSpeed);
            SetMovingSpeed(movingSpeed);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeDash()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dash") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeSwordSpin()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Sword Spin") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeThreeWayCut()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Three-Way Cut") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeStrongBody()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Strong Body") {
            auto defence = GetDefence() + 5;
            auto movingSpeed = GetMovingSpeed() - 1;
            SetDefence(defence);
            SetMovingSpeed(movingSpeed);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeSpiritStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Spirit Strike") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeBash()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Bash") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeStump()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Stump") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}

void Warrior::UpgradeSwordStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Sword Strike") {
            auto attackValue = GetAttackValue() + 15;
            SetAttackValue(attackValue);
            SetSkillLevel(1);
        }
    }
}






