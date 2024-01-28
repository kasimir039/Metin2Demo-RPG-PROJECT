#include "Sura.h"

Sura::Sura(Player* player) : PlayerAbstraction(player),
Abilities(skillName, cooldown, requiredSp, attackPower, duration, defence, attackValue, attackSpeed, movingSpeed, skillLevel, targetSelf, targetEnemy, targetMultiple, weaponEffect, unarmedEffect),
stats(nullptr)
{
}


void Sura::Display() const noexcept {
    std::cout << "Sura \n";
    std::cout << "--------- \n";
}

void Sura::SuraBlackMagicSkills()
{
    DarkOrb();
    DarkProtection();
    DarkStrike();
    FlameSpirit();
    FlameStrike();
    SpiritStrike();
}

void Sura::SuraWeaponarySkills()
{
    Dispel();
    DragonSwirl();
    EnchantedArmour();
    EnchantedBlade();
    Fear();
    FingerStrike();
}

void Sura::DarkOrb()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dark Orb", 24, 91, 0, 0, 0, 925, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::DarkProtection()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dark Protection", 69, 21, 0, 66, 3, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));
}

void Sura::DarkStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dark Strike", 7, 37, 0, 0, 0, 806, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));
}

void Sura::FlameSpirit()
{
    Ability.emplace_back(std::make_unique<Abilities>("Flame Spirit", 44, 21, 0, 30, 0, 461, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE));
}

void Sura::FlameStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Flame Strike", 12, 67, 0, 0, 0, 771, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));
}

void Sura::SpiritStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Spirit Strike", 12, 46, 0, 0, 0, 516, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::Dispel()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dispel", 12, 36, 0, 0, 0, 795, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::DragonSwirl()
{
    Ability.emplace_back(std::make_unique<Abilities>("Dragon Swirl", 15, 57, 0, 0, 0, 721, 0, 0, 1, ABILITYTARGET::NONE, ABILITYTARGET::ENEMY, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::EnchantedArmour()
{
    Ability.emplace_back(std::make_unique<Abilities>("Enchanted Armour", 40, 78, 0, 36, 6, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::MULTIPLE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::EnchantedBlade()
{
    Ability.emplace_back(std::make_unique<Abilities>("Enchanted Blade", 0, 32, 24, 55, 0, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON));

}

void Sura::Fear()
{
    //Calculation will be made to reduce the attack value
    Ability.emplace_back(std::make_unique<Abilities>("Fear", 100, 66, 0, 65, 0, 0, 0, 0, 1, ABILITYTARGET::SELF, ABILITYTARGET::NONE, ABILITYTARGET::NONE, WEAPONEFFECT::WEAPON, WEAPONEFFECT::UNARMED));

}

void Sura::FingerStrike()
{
    Ability.emplace_back(std::make_unique<Abilities>("Finger Strike",10,37,0,0,0,715,0,0,1,ABILITYTARGET::NONE,ABILITYTARGET::ENEMY,ABILITYTARGET::NONE,WEAPONEFFECT::WEAPON,WEAPONEFFECT::UNARMED));
}

void Sura::GetDarkOrb() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dark Orb")
        {

            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetDarkProtection() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dark Protection")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Defence: " << ability->GetDefence() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetDarkStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dark Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetFlameSpirit() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Flame Spirit")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetFlameStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Flame Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetSpiritStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Spirit Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            std::cout << "------------------------\n";
            break;
        }
    }
}

void Sura::GetDispel() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dispel")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetDragonSwirl() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Dragon Swirl")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetEnchantedArmour() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Enchanted Armour")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Defence: " << ability->GetDefence() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetEnchtantedBlade() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Enchanted Blade")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Power: " << ability->GetAttackPower() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }

}

void Sura::GetFear() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Fear")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "Duration: " << ability->GetDuration() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            break;
        }
    }
}

void Sura::GetFingerStrike() const
{
    for (const auto& ability : Ability)
    {
        if (ability->GetSkillName() == "Finger Strike")
        {
            std::cout << "------------------------\n";
            std::cout << "Ability Name: " << ability->GetSkillName() << "\n";
            std::cout << "Skill Level: " << ability->GetSkillLevel() << "\n";
            std::cout << "Attack Value: " << ability->GetAttackValue() << "\n";
            std::cout << "Cooldown: " << ability->GetCooldown() << "\n";
            std::cout << "SP Required: " << ability->GetSp() << "\n";
            std::cout << "------------------------\n";
            break;
        }
    }
}

void Sura::UpgradeDarkOrb()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dark Orb") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeDarkProtection()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dark Protection") {

            ability->SetDefence(10);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeDarkStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dark Strike") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeFlameSpirit()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Flame Spirit") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeFlameStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Flame Strike") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeSpiritStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Spirit Strike") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeDispel()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dispel") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeDragonSwirl()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Dragon Swirl") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeEnchantedArmour()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Enchanted Armour") {

            ability->SetDefence(10);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeEnchtantedBlade()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Enchanted Blade") {

            ability->SetAttackPower(5);
            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeFear()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Fear") {

            ability->SetSkillLevel(1);
            break;
        }
    }
}

void Sura::UpgradeFingerStrike()
{
    for (const auto& ability : Ability) {
        if (ability->GetSkillName() == "Finger Strike") {

            ability->SetAttackValue(15);
            ability->SetSkillLevel(1);
            break;
        }
    }
}