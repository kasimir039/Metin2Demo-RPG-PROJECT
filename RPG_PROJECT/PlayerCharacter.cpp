#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(const std::string& name,CHARACTER character,KINGDOM kingdom, statusType VIT, statusType INT, statusType STR, statusType DEX)
    : characterType(character),kingdom(kingdom), experience(0u), level(1u), requiredExperience(50u), statsPoint(0u),warrior(NULL),skillScore(0),sura(NULL)
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
        for (const auto& ability : warrior.Ability) {
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

    auto totalDefence = 0;

    if (!armors.empty())
    {
        totalDefence = Armor::GetArmorDef() + stats->GetDexPoint();

    }
    else if(armors.empty())
    {
        totalDefence = stats->GetDexPoint();

    }

    if (UseStrongBody())
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Strong Body") {
                totalDefence += ability->GetDefence();
                break;
            }
        }
    }

    return totalDefence;
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
    ChooseSuraSkills();
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
            case CHOOSE_WARRIOR_SKILLS::BODY:
            {
                warrior.BodyWarriorSkills();
                GetWarriorBodySkills();
                continueLoop = false;
                break;
            }
            case CHOOSE_WARRIOR_SKILLS::MENTAL:
            {
                warrior.MentalWarriorSkills();
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
        
        warrior.GetAuraOfTheSword();
        warrior.GetBerserk();
        warrior.GetDash();
        warrior.GetSwordSpin();
        warrior.GetThreeWayCut();
    }
}

void PlayerCharacter::GetWarriorMentalSkills() const noexcept
{
    if (characterType == CHARACTER::WARRIOR)
    {
        std::cout << "Warrior Mental Skills:\n";
        std::cout << "------------------------\n";

        warrior.GetStrongBody();
        warrior.GetSpiritStrike();
        warrior.GetBash();
        warrior.GetStump();
        warrior.GetSwordStrike();

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
                warrior.UpgradeAuraOfTheSword();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::BERSERK:
            {
                warrior.UpgradeBerserk();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::DASH:
            {
                warrior.UpgradeDash();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SWORD_SPÝN:
            {
                warrior.UpgradeSwordSpin();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::THREE_WAY_CUT:
            {
                warrior.UpgradeThreeWayCut();
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
                warrior.UpgradeStrongBody();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SPIRIT_STRIKE_WARRIOR:
            {
                warrior.UpgradeSpiritStrike();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::BASH:
            {
                warrior.UpgradeBash();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::STUMP:
            {
                warrior.UpgradeStump();
                skillScore--;
                break;
            }
            case WARRIOR_SKILLS::SWORD_STRIKE:
            {
                warrior.UpgradeSwordStrike();
                skillScore--;
                break;
            }
            default:
                break;
            }
        }
    }

}

const bool PlayerCharacter::UseAuraOfTheSword()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Aura of the Sword") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseBerserk()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Berserk") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseDash()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Dash") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseSwordSpin()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Sword Swpin") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseThreeWayCut()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Three-Way Cut") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseStrongBody()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Strong Body") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseSpiritStrikeWarrior()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Spirit Strike") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseBash()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Bash") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseStump()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Stump") {
                return true;
            }
        }
    }
    return false;
}

const bool PlayerCharacter::UseSwordStrike()
{
    if (characterType == CHARACTER::WARRIOR)
    {
        for (const auto& ability : warrior.Ability) {
            if (ability->GetSkillName() == "Sword Strike") {
                return true;
            }
        }
    }
    return false;
}

void PlayerCharacter::ChooseSuraSkills()
{
    if (level >= 5 && characterType == CHARACTER::SURA)
    {

        bool continueLoop = true;

        while (continueLoop)
        {
            int choice = 0;
            std::cout << "Please specify the skill you want to choose\n\
       1)BLACK MAGIC\n\
       2)WEAPONARY\n";

            std::cin >> choice;

            switch (choice)
            {
            case CHOOSE_SURA_SKILLS::BLACK_MAGIC:
            {
                sura.SuraBlackMagicSkills();
                GetSuraBlackMagicSkills();
                continueLoop = false;
                break;
            }
            case CHOOSE_SURA_SKILLS::WEAPONARY:
            {
                sura.SuraWeaponarySkills();
                GetSuraWeaponarySkills();
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

void PlayerCharacter::GetSuraBlackMagicSkills() const
{
    if (characterType == CHARACTER::SURA)
    {


        std::cout << "Sura Black Magic Skills:\n";
        std::cout << "------------------------\n";

        sura.GetDarkProtection();
        sura.GetFlameSpirit();
        sura.GetDarkOrb();
        sura.GetDarkStrike();
        sura.GetFlameStrike();
        sura.GetFlameSpirit();
    }
}

void PlayerCharacter::GetSuraWeaponarySkills() const
{
    if (characterType == CHARACTER::SURA)
    {


        std::cout << "Sura Weaponary Skills:\n";
        std::cout << "------------------------\n";

        sura.GetEnchtantedBlade();
        sura.GetEnchantedArmour();
        sura.GetDispel();
        sura.GetDragonSwirl();
        sura.GetFear();
        sura.GetFingerStrike();
    }

}

void PlayerCharacter::UpgradeSuraBlackMagicSkills()
{
    if (characterType == CHARACTER::SURA)
    {
        while (skillScore)
        {
            std::cout << "\nChoose which skills you want to develop\n";
            std::cout << "1)Dark Protection\n2)Flame Spirit\n3)Dark Orb\n4)Dark Strike\n5)Flame Strike\n6)Spirit Strike\n";
            int choice = 0;
            std::cin >> choice;


            switch (choice)
            {
            case SURA_SKILLS::DARK_PROTECTION:
            {
                sura.UpgradeDarkProtection();
                skillScore--;
                break;
            }
            case SURA_SKILLS::FLAME_SPIRIT:
            {
                sura.UpgradeFlameSpirit();
                skillScore--;
                break;
            }
            case SURA_SKILLS::DARK_ORB:
            {
                sura.UpgradeDarkOrb();
                skillScore--;
                break;
            }
            case SURA_SKILLS::DARK_STRIKE:
            {
                sura.UpgradeDarkStrike();
                skillScore--;
                break;
            }
            case SURA_SKILLS::FLAME_STRIKE:
            {
                sura.UpgradeFlameStrike();
                skillScore--;
                break;
            }
            case SURA_SKILLS::SPIRIT_STRIKE_SURA:
            {
                sura.UpgradeSpiritStrike();
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

void PlayerCharacter::UpgradeSuraWeaponarySkills()
{
    if (characterType == CHARACTER::SURA)
    {
        while (skillScore)
        {
            std::cout << "\nChoose which skills you want to develop\n";
            std::cout << "1)Enchanted Blade\n2)Enchanted Armour\n3)Dispel\n4)Dragon Swirl\n5)Fear\n6)Finger Strike\n";
            int choice = 0;
            std::cin >> choice;


            switch (choice)
            {
            case SURA_SKILLS::ENCHANTED_BLADE:
            {
                sura.UpgradeEnchtantedBlade();
                skillScore--;
                break;
            }
            case SURA_SKILLS::ENCHANTED_ARMOUR:
            {
                sura.UpgradeEnchantedArmour();
                skillScore--;
                break;
            }
            case SURA_SKILLS::DISPEL:
            {
                sura.UpgradeDispel();
                skillScore--;
                break;
            }
            case SURA_SKILLS::DRAGON_SWIRL:
            {
                sura.UpgradeDragonSwirl();
                skillScore--;
                break;
            }
            case SURA_SKILLS::FEAR:
            {
                sura.UpgradeFear();
                skillScore--;
                break;
            }
            case SURA_SKILLS::FINGER_STRIKE:
            {
                sura.UpgradeFingerStrike();
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



