#pragma once
#include "StatBlock.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include <vector>

enum KINGDOM { CHUNJO = 1, JINNO, SHINSOO };
enum STATS { VIT = 1, INT, STR,DEX };

class PlayerCharacter : public Player
{
private:
	bool CheckLevel();
	void IncreaseStats();

	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;


	std::string characterName;
	KINGDOM kingdom;
	expType experience;
	expType requiredExperience;
	levelType level;
	statusType statsPoint;

	const size_t maxNameLength = 12;
	const levelType maxLevel = 99u;

	StatBlock stats;

public:

	PlayerCharacter(const std::string& name,KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX);
	
	PlayerCharacter() = delete;
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

	const void DisplayWeapons() const;
	const void DisplayArmor() const;
	const equipmentType MaxWeaponAttack() const;
	const equipmentType MinWeaponAttack() const;
	const equipmentType MaxArmorHealthPoint() const;
	const equipmentType MaxArmorDefense() const;

};


