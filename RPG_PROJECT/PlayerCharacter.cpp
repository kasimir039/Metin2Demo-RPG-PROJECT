#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(std::string name, KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX)
    : characterName(name),kingdom(kingdom), stats(VIT, INT, STR, DEX), experience(0u), level(1u), requiredExperience(100u), statsPoint(0u) {}

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


const equipmentType PlayerCharacter::MaxAttack() const
{

    if (!weapons.empty())
    {
        auto val = Weapon::GetWeaponPower() + stats.GetStrengthPoint();
        return val;
    }
    return 0;
}

const equipmentType PlayerCharacter::MinAttack() const
{

    if (!weapons.empty())
    {
        for (const auto& weapon : weapons)
        {
            auto value = weapon->GetWeaponPower();
            return value;
        }

    }
    return stats.GetStrengthPoint();
}

const equipmentType PlayerCharacter::MaxHealthPoint() const
{
    if (!armors.empty())
    {
        auto val = Armor::GetArmorHp() + stats.GetHealthPoint();
        return val;
    }
    return stats.GetHealthPoint();
}


const equipmentType PlayerCharacter::MaxDefense() const
{
    if (!armors.empty())
    {
        auto val = Armor::GetArmorDef() + stats.GetDurabilityPoint();
        return val;
    }
    return stats.GetDurabilityPoint();
}


void PlayerCharacter::GainExperience(expType expAmount)
{
    experience += expAmount;
    while(checkLevel());

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
        auto defValue = stats.GetDurabilityPoint();
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

    if (level > 1)
    {
        statsPoint = 3;

        std::cout << "Choose which features you want to upgrade\n";


        while (statsPoint > 0)
        {
            int choice;
            std::cout << "1. VIT\n";
            std::cout << "2. INT\n";
            std::cout << "3. STR\n";
            std::cout << "4. DEX\n";
 
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                auto healthValue = stats.GetHealth();
                healthValue += 1;
                stats.SetHealth(healthValue);
                stats.CalculateHealthPoint();
                break;
            }
            case 2:
            {
                auto intelligenceValue = stats.GetIntelligence();
                intelligenceValue += 1;
                stats.SetIntelligence(intelligenceValue);
                stats.CalculateIntelligencePoint();
                break;
            }
            case 3:
            {
                auto strengthValue = stats.GetStrength();
                strengthValue += 1;
                stats.SetStrength(strengthValue);
                stats.CalculateStrengthPoint();
                break;
            }
            case 4:
            {
                auto durabilityValue = stats.GetDurability();
                durabilityValue += 1;
                stats.SetDurability(durabilityValue);
                stats.CalculateDurabilityPoint();
                break;
            }
            default:
                std::cout << "Invalid selection, try again.\n";
                break;
            }

            statsPoint--;
        }

    }
}

bool PlayerCharacter::checkLevel()
{
    static const uint16_t EXPINCREASE = 2u;
    if (experience >= requiredExperience)
    {
        ++level;
        std::cout << "LEVEL UP!: " << level << '\n';
        requiredExperience *= EXPINCREASE;
        experience = 0u;
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
        << "VIT: " << stats.GetHealth() << " |" << " HP:" << MaxHealthPoint() <<  '\n'
        << "INT: " << stats.GetIntelligence() << " |" << " SP:" << stats.GetIntelligencePoint() << '\n'
        << "STR: " << stats.GetStrength() << " |" << " Attack Power:" << MinAttack() << " - " << MaxAttack() << '\n'
        << "DEX: " << stats.GetDurability() << " |" << " Defense:" << MaxDefense() << '\n' << '\n';

}

