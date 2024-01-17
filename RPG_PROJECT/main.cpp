#include <iostream>
#include "pc.h"

PlayerCharacter* selectedCharacter = nullptr;

enum CH{WARRIOR=1,SURA,SHAMAN,ASSASSIN};


void CreateWarriorCharacter(PlayerCharacter*& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;


    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";
    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case CHUNJO:
    {
        character = new PlayerCharacter(name, KINGDOM::CHUNJO, 4u, 3u, 6u, 3u);
        break;
    }
    case JINNO:
    {
        character = new PlayerCharacter(name, KINGDOM::JINNO, 4u, 3u, 6u, 3u);
        break;
    }
    case SHINSOO:
    {
        character = new PlayerCharacter(name, KINGDOM::SHINSOO, 4u, 3u, 6u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }


}
void CreateSuraCharacter(PlayerCharacter*& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case CHUNJO:
    {
        character = new PlayerCharacter(name, KINGDOM::CHUNJO, 6u, 4u, 3u, 3u);
        break;
    }
    case JINNO:
    {
        character = new PlayerCharacter(name, KINGDOM::JINNO, 6u, 4u, 3u, 3u);
        break;
    }
    case SHINSOO:
    {
        character = new PlayerCharacter(name, KINGDOM::SHINSOO, 6u, 4u, 3u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}
void CreateShamanCharacter(PlayerCharacter*& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(2)JINNO\n";
    std::cout << "(3)SHINSOO\n";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case CHUNJO:
    {
        character = new PlayerCharacter(name, KINGDOM::CHUNJO, 4u, 6u, 3u, 3u);
        break;
    }
    case JINNO:
    {
        character = new PlayerCharacter(name, KINGDOM::JINNO, 4u, 6u, 3u, 3u);
        break;
    }
    case SHINSOO:
    {
        character = new PlayerCharacter(name, KINGDOM::SHINSOO, 4u, 6u, 3u, 3u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}
void CreateAssassinCharacter(PlayerCharacter*& character)
{
    std::string name;
    std::cout << "Character Name: ";
    std::cin >> name;

    std::cout << "Kingdom: \n";
    std::cout << "(1)CHUNJO\n";
    std::cout << "(3)SHINSOO\n";
    std::cout << "(2)JINNO\n";

    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case CHUNJO:
    {
        character = new PlayerCharacter(name, KINGDOM::CHUNJO, 3u, 3u, 4u, 6u);
        break;
    }
    case JINNO:
    {
        character = new PlayerCharacter(name, KINGDOM::JINNO, 3u, 3u, 4u, 6u);
        break;
    }
    case SHINSOO:
    {
        character = new PlayerCharacter(name, KINGDOM::SHINSOO, 3u, 3u, 4u, 6u);
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}
void CreateMainCharacter()
{
    std::cout << "Create your Character:\n\n";
    std::cout << "(1)WARRIOR\n";
    std::cout << "(2)SURA\n";
    std::cout << "(3)SHAMAN\n";
    std::cout << "(4)ASSASSIN\n";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case WARRIOR:
    {
        CreateWarriorCharacter(selectedCharacter);
        Warrior* warrior = new Warrior(selectedCharacter);

        warrior->Display();

        delete warrior;
        warrior = nullptr;
        break;
    }
    case SURA:
    {
        CreateSuraCharacter(selectedCharacter);
        Sura* sura = new Sura(selectedCharacter);

        sura->Display();

        delete sura;
        sura = nullptr;
        break;
    }
    case SHAMAN:
    {
        CreateShamanCharacter(selectedCharacter);
        Shaman* shaman = new Shaman(selectedCharacter);

        shaman->Display();

        delete shaman;
        shaman = nullptr;
        break;
    }
    case ASSASSIN:
    {
        CreateAssassinCharacter(selectedCharacter);
        Assassin* assassin = new Assassin(selectedCharacter);

        assassin->Display();

        delete assassin;
        assassin = nullptr;
        break;
    }
    default:
        std::cout << "UNKNOWN";
        break;
    }
}

int main()
{
    CreateMainCharacter();

    while (true)
    {
        if (selectedCharacter)
        {
            selectedCharacter->DisplayCharacter();

            Weapon* sword = new Weapon("Sword", 50);
            Armor* armor = new Armor("Iron Plate", 25, 60);


            //selectedCharacter->GainExperience(200);

            if (sword)
            {
                //selectedCharacter->EquipWeapon(sword);
                //selectedCharacter->DisplayWeapons();
            }
            if (armor)
            {

                //selectedCharacter->EquipArmor(armor);
                //selectedCharacter->DisplayArmor();

            }

            /*
            selectedCharacter->TakeDamage(5);

            selectedCharacter->IncreaseHealth(3);

            selectedCharacter->DisplayCharacter();

            selectedCharacter->IncreaseHealth(3);
            */

            selectedCharacter->DisplayCharacter();


            delete sword;
            sword = nullptr;

            delete armor;
            armor = nullptr;

            delete selectedCharacter;
            selectedCharacter = nullptr;
            
        }
    }

	return EXIT_SUCCESS;
}