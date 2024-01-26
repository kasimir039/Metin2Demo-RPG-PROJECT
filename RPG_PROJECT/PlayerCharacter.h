#pragma once
#include "StatBlock.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Warrior.h"
#include <vector>

enum CHARACTER { WARRIOR = 1, SURA, SHAMAN, ASSASSIN };
enum KINGDOM { CHUNJO = 1, JINNO, SHINSOO };
enum STATS { VIT = 1, INT, STR, DEX };
enum SKILLS { BODY = 1, MENTAL };
enum WARRIOR_SKILLS { AURA_OF_THE_SWORD = 1, BERSERK, DASH, SWORD_SPÝN, THREE_WAY_CUT, STRONG_BODY, SPIRIT_STRIKE, BASH, STUMP, SWORD_STRIKE };


class PlayerCharacter : public Player
{
private:
	bool CheckLevel();
	void IncreaseStats();

	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;
	StatBlock stats;
	Warrior w;

	std::string characterName;
	KINGDOM kingdom;
	CHARACTER characterType;
	expType experience;
	expType requiredExperience;
	levelType level;
	statusType statsPoint;
	skillType skillScore;



	static constexpr size_t maxNameLength = 12;
	static constexpr levelType maxLevel = 99u;


public:

	PlayerCharacter(const std::string& name,CHARACTER character,KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX);
	

	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;


	const void DisplayCharacter() const noexcept override;

	//Getters
	const std::string GetCharacterName() const noexcept;
	const std::string GetKingdom() const noexcept;
	const expType GetExp() const noexcept;
	const expType GetRequiredExp() const noexcept;
	const levelType GetLevel() const noexcept;
	const statusType GetStatsPoint() const noexcept;
	
	//Functions
	void GainExperience(expType exp);
	void EquipWeapon(Weapon* weapon);
	void EquipArmor(Armor* armor);
	void TakeDamage(statusType damage);
	void IncreaseHealth(statusType value);
	
	void ChooseSkills();

	void ChooseWarriorSkills();
	void GetWarriorBodySkills();
	void GetWarriorMentalSkills();
	
	void UpgradeWarriorBodyAbilities();
	void UpgradeWarriorMentalAbilities();

	const skillType UseAuraOfTheSword() const;

	const void DisplayWeapons() const;
	const void DisplayArmor() const;
	const equipmentType MaxWeaponAttack() const;
	const equipmentType MinWeaponAttack() const;
	const equipmentType MaxArmorHealthPoint() const;
	const equipmentType MaxArmorDefense() const;

};


