#include <iostream>
#include "pc.h"
#include <memory>

std::unique_ptr<PlayerCharacter> selectedCharacter = nullptr;

void CreateWarriorCharacter(std::unique_ptr<PlayerCharacter>& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case KINGDOM::CHUNJO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::WARRIOR, KINGDOM::CHUNJO, 4u, 3u, 6u, 3u);
        break;
    }
    case KINGDOM::JINNO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::WARRIOR, KINGDOM::JINNO, 4u, 3u, 6u, 3u);
        break;
    }
    case KINGDOM::SHINSOO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::WARRIOR, KINGDOM::SHINSOO, 4u, 3u, 6u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}

void CreateSuraCharacter(std::unique_ptr<PlayerCharacter>& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case CHUNJO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SURA, KINGDOM::CHUNJO, 6u, 4u, 3u, 3u);
        break;
    }
    case JINNO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SURA, KINGDOM::JINNO, 6u, 4u, 3u, 3u);
        break;
    }
    case SHINSOO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SURA, KINGDOM::SHINSOO, 6u, 4u, 3u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}

void CreateShamanCharacter(std::unique_ptr<PlayerCharacter>& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case CHUNJO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SHAMAN, KINGDOM::CHUNJO, 4u, 6u, 3u, 3u);
        break;
    }
    case JINNO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SHAMAN, KINGDOM::JINNO, 4u, 6u, 3u, 3u);
        break;
    }
    case SHINSOO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::SHAMAN, KINGDOM::SHINSOO, 4u, 6u, 3u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}

void CreateAssassinCharacter(std::unique_ptr<PlayerCharacter>& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case CHUNJO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::ASSASSIN, KINGDOM::CHUNJO, 3u, 3u, 4u, 6u);
        break;
    }
    case JINNO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::ASSASSIN, KINGDOM::JINNO, 3u, 3u, 4u, 6u);
        break;
    }
    case SHINSOO:
    {
        character = std::make_unique<PlayerCharacter>(name, CHARACTER::ASSASSIN, KINGDOM::SHINSOO, 3u, 3u, 4u, 6u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}

void CreateMainCharacter()
{
    while (!selectedCharacter)
    {
        std::cout << "Create your Character:\n\n";
        std::cout << "(1)WARRIOR\n";
        std::cout << "(2)SURA\n";
        std::cout << "(3)SHAMAN\n";
        std::cout << "(4)ASSASSIN\n";

        int choice = 0;
        std::cin >> choice;

        switch (choice)
        {
        case WARRIOR:
        {
            CreateWarriorCharacter(selectedCharacter);
            Warrior warrior(selectedCharacter.get());

            warrior.Display();
            break;
        }
        case SURA:
        {
            CreateSuraCharacter(selectedCharacter);
            Sura sura(selectedCharacter.get());

            sura.Display();
            break;
        }
        case SHAMAN:
        {
            CreateShamanCharacter(selectedCharacter);
            Shaman shaman(selectedCharacter.get());

            shaman.Display();
            break;
        }
        case CHARACTER::ASSASSIN:
        {
            CreateAssassinCharacter(selectedCharacter);
            Assassin assassin(selectedCharacter.get());

            assassin.Display();
            break;
        }
        default:
            std::cout << "UNKNOWN\n";
            break;
        }
    }
}

int main()
{
    CreateMainCharacter();

    while (true)
    {
        if (selectedCharacter)
        {
            auto sword = std::make_unique<Weapon>("Sword", 50);
            auto armor = std::make_unique<Armor>("Iron Plate", 25, 60);

            if (sword)
            {
                //selectedCharacter->EquipWeapon(sword.get());
                //selectedCharacter->DisplayWeapons();
            }
            if (armor)
            {
                //selectedCharacter->EquipArmor(armor.get());
                //selectedCharacter->DisplayArmor();
            }

            /*
            selectedCharacter->TakeDamage(5);

            selectedCharacter->DisplayCharacter();

            selectedCharacter->IncreaseHealth(3);

            selectedCharacter->DisplayCharacter();

            selectedCharacter->IncreaseHealth(3);

            selectedCharacter->DisplayCharacter();
            */
            selectedCharacter->DisplayCharacter();

            selectedCharacter->GainExperience(900);

            selectedCharacter->SetCheckSkills(true);
            selectedCharacter->UseStrongBody();

            selectedCharacter->DisplayCharacter();
        }
    }

    return EXIT_SUCCESS;
}
