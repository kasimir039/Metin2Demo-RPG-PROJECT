#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(const std::string& name,CHARACTER character,KINGDOM kingdom, statusType VIT, statusType INT, statusType STR, statusType DEX)
    : characterType(character),kingdom(kingdom), experience(0u), level(1u), requiredExperience(50u), statsPoint(0u),w(NULL),skillScore(0)
{
    characterName = name.substr(0, maxNameLength);
    stats = new StatBlock(VIT, INT, STR, DEX);  

}

PlayerCharacter::~PlayerCharacter() {
    delete stats;
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

const equipmentType PlayerCharacter::MaxWeaponAttack() 
{
    auto totalAttackPower = 0;

    if (!weapons.empty())
    {
        totalAttackPower = Weapon::GetWeaponPower() + stats->GetStrengthPoint();
    }

    if (UseAuraOfTheSword() && !weapons.empty()) {
        for (const auto& ability : w.Ability) {
            if (ability->GetSkillName() == "Aura of the Sword") {
                totalAttackPower += ability->GetAttackPower();
                break;
            }
        }
    }

    return totalAttackPower;
}

const equipmentType PlayerCharacter::MinWeaponAttack() 
{

    if (!weapons.empty())
    {
        for (const auto& weapon : weapons)
        {
            auto value = weapon->GetWeaponPower() + stats->GetStrengthPoint();
            return value;
        }

    }

    auto strengthVal = stats->GetStrengthPoint();

    return strengthVal;
}

const equipmentType PlayerCharacter::MaxArmorHealthPoint()
{
    if (!armors.empty())
    {
        auto value = Armor::GetArmorHp() + stats->GetHealthPoint();
        return value;
    }

    auto healthVal = stats->GetHealthPoint();

    return healthVal;
}


const equipmentType PlayerCharacter::MaxArmorDefense()
{
    if (!armors.empty())
    {
        auto value = Armor::GetArmorDef() + stats->GetDexPoint();
        return value;
    }

    auto durabilityVal = stats->GetDexPoint();

    return durabilityVal;
}

const bool PlayerCharacter::UseAuraOfTheSword() 
{
    for (const auto& ability : w.Ability) {
        if (ability->GetSkillName() == "Aura of the Sword") {
            return true;
        }
    }
    return false;

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

        auto value = stats->GetStrengthPoint();

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
        auto hpValue = stats->GetHealthPoint();
        auto defValue = stats->GetDexPoint();

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
                currentValue = stats->GetVit();
                maxValue = stats->GetMaxVit();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats->SetVit(currentValue);
                    stats->CalculateHealthPoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue<<'\n';
                continue;
            }
            case INT:
            {
               currentValue = stats->GetInt();
               maxValue = stats->GetMaxInt();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats->SetInt(currentValue);
                    stats->CalculateIntelligencePoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue << '\n';
                continue;
            }
            case STR:
            {
               currentValue = stats->GetStr();
               maxValue = stats->GetMaxStr();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats->SetStr(currentValue);
                    stats->CalculateStrengthPoint();
                    break;
                }
                std::cout << "\nPlease make another choice, status limit exceeded. " << maxValue << '\n';
                continue;
            }
            case DEX:
            {
               currentValue = stats->GetDex();
               maxValue = stats->GetMaxDex();

                if (currentValue < maxValue)
                {
                    currentValue += 1;
                    stats->SetDex(currentValue);
                    stats->CalculateDexPoint();
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
        ++skillScore;
        std::cout << "LEVEL UP!: " << level << '\n';
        std::cout << "You earned points to improve your skillss: " << skillScore << '\n';
        requiredExperience *= EXPINCREASE;
        experience = excessExp;
        IncreaseStats();


        ChooseSkills();

        return true;
    }


    return false;
}


const void PlayerCharacter::DisplayCharacter() noexcept
{

    std::cout << '\n'<<"Character Name: " << GetCharacterName() << " | " << "Kingdom: " << GetKingdom() << '\n'
        << "Level: " << GetLevel() << " |" << " Exp: " << GetExp() << " | " << "Required exp: " << GetRequiredExp() << '\n'
        << "Status Point: " << GetStatsPoint() << '\n'
        << "VIT: " << stats->GetVit() << " |" << " HP:" << MaxArmorHealthPoint() <<  '\n'
        << "INT: " << stats->GetInt() << " |" << " SP:" << stats->GetIntelligencePoint() << '\n'
        << "STR: " << stats->GetStr() << " |" << " Attack Power:" << MinWeaponAttack() << " - " << MaxWeaponAttack() << '\n'
        << "DEX: " << stats->GetDex() << " |" << " Defense:" << MaxArmorDefense() << '\n' << '\n';

}

void PlayerCharacter::TakeDamage(statusType damage)
{
    auto hp = stats->GetHealthPoint();

    if (damage > hp)
    {
        stats->SetHealthPoint(0);
    }

    stats->SetHealthPoint(hp - damage);
    std::cout << "Damage Received: " << damage << '\n';

}

void PlayerCharacter::IncreaseHealth(statusType value)
{
    
    auto hp = stats->GetHealthPoint();
    const auto maxHp = stats->GetMaxHealthPoint();

    if (hp + value > maxHp)
    {
        std::cout << "Health points full: " << maxHp << '\n';
        stats->SetHealthPoint(maxHp);
    }
    else
    {
        stats->SetHealthPoint(hp + value);
        std::cout << "Increased Amount of Health: " << value<<'\n';
    }
    
}

void PlayerCharacter::ChooseSkills()
{
    ChooseWarriorSkills();
    //ChooseSuraSkills;
    //ChooseShamanSkills;
    //ChooseAssassinSkills;
}

void PlayerCharacter::ChooseWarriorSkills()
{

    if (level >= 5 && characterType == CHARACTER::WARRIOR)
    {

        bool continueLoop = true;

        while (continueLoop)
        {
            int choice = 0;
            std::cout << "Please specify the skill you want to choose\n\
       1)BODY\n\
       2)MENTAL\n";

            std::cin >> choice;

            switch (choice)
            {
            case SKILLS::BODY:
            {
                w.BodyWarriorSkills();
                GetWarriorBodySkills();
                continueLoop = false;
                break;
            }
            case SKILLS::MENTAL:
            {
                w.MentalWarriorSkills();
                GetWarriorMentalSkills();
                continueLoop = false;
                break;
            }
            default:
                std::cout << "Wrong choice\n";
                break;
            }
        }
    }
}

void PlayerCharacter::GetWarriorBodySkills() const noexcept
{
    if (characterType == CHARACTER::WARRIOR)
    {


        std::cout << "Warrior Body Skills:\n";
        std::cout << "------------------------\n";
        
        w.GetAuraOfTheSword();
        w.GetBerserk();
        w.GetDash();
        w.GetSwordSpin();
        w.GetThreeWayCut();
    }
}

void PlayerCharacter::GetWarriorMentalSkills() const noexcept
{
    if (characterType == CHARACTER::WARRIOR)
    {
        std::cout << "Warrior Mental Skills:\n";
        std::cout << "------------------------\n";

        w.GetStrongBody();
        w.GetSpiritStrike();
        w.GetBash();
        w.GetStump();
        w.GetSwordStrike();

    }
}


void PlayerCharacter::UpgradeWarriorBodyAbilities()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        while (skillScore)
        {
        std::cout << "\nChoose which skills you want to develop\n";
        std::cout << "1)Aura of The Sword\n2)Berserk\n3)Dash\n4)Sword Spin\n5)Three-Way-Cut\n";
        int choice = 0;
        std::cin >> choice;


            switch (choice)
            {
            case WARRIOR_SKILLS::AURA_OF_THE_SWORD:
            {
                w.UpgradeAuraOfTheSword();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::BERSERK:
            {
                w.UpgradeBerserk();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::DASH:
            {
                w.UpgradeDash();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SWORD_SPÝN:
            {
                w.UpgradeSwordSpin();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::THREE_WAY_CUT:
            {
                w.UpgradeThreeWayCut();
                skillScore--;
                break;
            }
            default:
                std::cout << "Invalid choice. Please choose a valid skill\n";
                break;
            }
        }
    }

}

void PlayerCharacter::UpgradeWarriorMentalAbilities()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        while (skillScore)
        {
        std::cout << "\nChoose which skills you want to develop\n";
        std::cout << "1)Strong Body\n2)Spirit Strike\n3)Bash\n4)tump\n5)Sword Strike\n";
        int choice = 0;
        std::cin >> choice;

            switch (choice)
            {
            case WARRIOR_SKILLS::STRONG_BODY:
            {
                w.UpgradeStrongBody();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SPIRIT_STRIKE:
            {
                w.UpgradeSpiritStrike();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::BASH:
            {
                w.UpgradeBash();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::STUMP:
            {
                w.UpgradeStump();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SWORD_STRIKE:
            {
                w.UpgradeSwordStrike();
                skillScore--;
                break;
            }
            default:
                break;
            }
        }
    }

}

