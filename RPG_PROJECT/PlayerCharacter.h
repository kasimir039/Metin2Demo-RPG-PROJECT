#pragma once
#include "StatBlock.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include <vector>

enum KINGDOM { CHUNJO = 1, JINNO, SHINSOO };
enum KINGDOM { VIT = 1, INT, STR,DEX };

class PlayerCharacter : public Player
{
private:
	bool checkLevel();
	void IncreaseStats();

	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;

protected:

	std::string characterName;
	KINGDOM kingdom;
	expType experience;
	expType requiredExperience;
	levelType level;
	const levelType maxLevel = 99;
	StatBlock stats;
	statusType statsPoint;

	PlayerCharacter() = delete;
	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;

public:

	PlayerCharacter(std::string name,KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX);

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
	const void DisplayWeapons() const;
	const void DisplayArmor() const;
	void TakeDamage(statusType damage);
	void IncreaseHealth(statusType value);

	const equipmentType MaxWeaponAttack() const;
	const equipmentType MinWeaponAttack() const;
	const equipmentType MaxArmorHealthPoint() const;
	const equipmentType MaxArmorDefense() const;

};


