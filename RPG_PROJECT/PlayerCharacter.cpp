#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(const std::string& name, KINGDOM kingdom, statusType VIT, statusType INT, statusType STR, statusType DEX)
    : kingdom(kingdom), stats(VIT, INT, STR, DEX), experience(0u), level(1u), requiredExperience(50u), statsPoint(0u) 
{
    characterName = name.substr(0, maxNameLength);
}

const std::string PlayerCharacter::GetCharacterName() const noexcept { return characterName; }

const std::string PlayerCharacter::GetKingdom() const noexcept
{

    if (kingdom == KINGDOM::CHUNJO)
    {
        return "Chunjo";
    }
    else if (kingdom == KINGDOM::JINNO)
    {
        return "Jinno";
    }
    else if (kingdom == KINGDOM::SHINSOO)
    {
        return "Shinsoo";
    }

    return "UNKNOWN";
}

const expType PlayerCharacter::GetExp() const noexcept { return experience; }
const expType PlayerCharacter::GetRequiredExp() const noexcept { return requiredExperience; }
const levelType PlayerCharacter::GetLevel() const noexcept { return level; }
const levelType PlayerCharacter::GetStatsPoint() const noexcept{ return statsPoint; }

const void PlayerCharacter::DisplayWeapons() const
{
    std::cout << "Equipped Weapons:\n";
    for (const auto& weapon : weapons) {
        std::cout << weapon->GetEquipmentName() << " (Attack Power: " << weapon->GetWeaponPower() << ")\n";
    }
}

const void PlayerCharacter::DisplayArmor() const
{
    std::cout << "Equipped Armor:\n";
    for (const auto& armor : armors) {
        std::cout << armor->GetEquipmentName() << " (Health Power: " << armor->GetArmorHp() << ")" << "(Defense : " << armor->GetArmorDef() << ")\n";
    }
   
}

const equipmentType PlayerCharacter::MaxWeaponAttack() const
{

    if (!weapons.empty())
    {
        auto value = Weapon::GetWeaponPower() + stats.GetStrengthPoint();
        
        return value;
    }
    return 0;
}

const equipmentType PlayerCharacter::MinWeaponAttack() const
{

    if (!weapons.empty())
    {
        for (const auto& weapon : weapons)
        {
            auto value = weapon->GetWeaponPower();
            return value;
        }

    }

    auto strengthVal = stats.GetStrengthPoint();

    return strengthVal;
}

const equipmentType PlayerCharacter::MaxArmorHealthPoint() const
{
    if (!armors.empty())
    {
        auto value = Armor::GetArmorHp() + stats.GetHealthPoint();
        return value;
    }

    auto healthVal = stats.GetHealthPoint();

    return healthVal;
}


const equipmentType PlayerCharacter::MaxArmorDefense() const
{
    if (!armors.empty())
    {
        auto value = Armor::GetArmorDef() + stats.GetDexPoint();
        return value;
    }

    auto durabilityVal = stats.GetDexPoint();

    return durabilityVal;
}

void PlayerCharacter::GainExperience(expType expAmount)
{
    if (level < maxLevel)
    {
        experience += expAmount;
        while (CheckLevel());
    }



}

void PlayerCharacter::EquipWeapon(Weapon* weapon)
{
        
    weapons.push_back(weapon);

    if (!weapons.empty())
    {

        auto value = stats.GetStrengthPoint();

        for (const auto& weapon : weapons)
        {
            value += weapon->GetWeaponPower();
        }

        std::cout << "Updated Attack Power with Weapon Power: " << value << '\n';
    }
    
}

void PlayerCharacter::EquipArmor(Armor* armor)
{

    armors.push_back(armor);

    if (!armors.empty())
    {
        auto hpValue = stats.GetHealthPoint();
        auto defValue = stats.GetDexPoint();

        for (const auto& armor : armors)
        {
            hpValue += armor->GetArmorHp();
            defValue += armor->GetArmorDef();
        }

        std::cout << "Updated Armor with Armor HP-DEF: " << "HP: " << hpValue

            << "DEF: " << defValue << '\n';
    }

}

void PlayerCharacter::IncreaseStats()
{
    auto currentValue = 0;
    auto maxValue = 0;

    if (level < maxLevel)
    {
        statsPoint = 3;

        std::cout << "Choose which features you want to upgrade\n";


        while (statsPoint > 0)
        {

            std::cout << "1. VIT\n";
            std::cout << "2. INT\n";
            std::cout << "3. STR\n";
            std::cout << "4. DEX\n";

            int choice;
            std::cin >> choice;

            switch (choice)
            {
            case VIT:
            {
                currentValue = stats.GetVit();
                maxValue = stats.GetMaxVit();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats.SetVit(currentValue);
                    stats.CalculateHealthPoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue<<'\n';
                continue;
            }
            case INT:
            {
               currentValue = stats.GetInt();
               maxValue = stats.GetMaxInt();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats.SetInt(currentValue);
                    stats.CalculateIntelligencePoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue << '\n';
                continue;
            }
            case STR:
            {
               currentValue = stats.GetStr();
               maxValue = stats.GetMaxStr();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats.SetStr(currentValue);
                    stats.CalculateStrengthPoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue << '\n';
                continue;
            }
            case DEX:
            {
               currentValue = stats.GetDex();
               maxValue = stats.GetMaxDex();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats.SetDex(currentValue);
                    stats.CalculateDexPoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue << '\n';
                continue;
            }
            default:
                std::cout << "Invalid selection, try again.\n";
                continue;
            }

            statsPoint--;
        }

    }
}

bool PlayerCharacter::CheckLevel()
{
    static const expType EXPINCREASE = 2u;

    if (level < maxLevel && experience >= requiredExperience)
    {
        expType excessExp = experience - requiredExperience;
        ++level;
        std::cout << "LEVEL UP!: " << level << '\n';
        requiredExperience *= EXPINCREASE;
        experience = excessExp;
        IncreaseStats();
        return true;
    }

    return false;
}


const void PlayerCharacter::DisplayCharacter() const noexcept
{

    std::cout << '\n'<<"Character Name: " << GetCharacterName() << " | " << "Kingdom: " << GetKingdom() << '\n'
        << "Level: " << GetLevel() << " |" << " Exp: " << GetExp() << " | " << "Required exp: " << GetRequiredExp() << '\n'
        << "Status Point: " << GetStatsPoint() << '\n'
        << "VIT: " << stats.GetVit() << " |" << " HP:" << MaxArmorHealthPoint() <<  '\n'
        << "INT: " << stats.GetInt() << " |" << " SP:" << stats.GetIntelligencePoint() << '\n'
        << "STR: " << stats.GetStr() << " |" << " Attack Power:" << MinWeaponAttack() << " - " << MaxWeaponAttack() << '\n'
        << "DEX: " << stats.GetDex() << " |" << " Defense:" << MaxArmorDefense() << '\n' << '\n';

}

void PlayerCharacter::TakeDamage(statusType damage)
{
    auto hp = stats.GetHealthPoint();

    if (damage > hp)
    {
        stats.SetHealthPoint(0);
    }

    stats.SetHealthPoint(hp - damage);
    std::cout << "Damage Received: " << damage << '\n';

}

void PlayerCharacter::IncreaseHealth(statusType value)
{
    
    auto hp = stats.GetHealthPoint();
    const auto maxHp = stats.GetMaxHealthPoint();

    if (hp + value > maxHp)
    {
        std::cout << "Health points full: " << maxHp << '\n';
        stats.SetHealthPoint(maxHp);
    }
    else
    {
        stats.SetHealthPoint(hp + value);
        std::cout << "Increased Amount of Health: " << value<<'\n';
    }

}
