#pragma once
#include "StatBlock.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include <vector>

enum KINGDOM { CHUNJO = 1, JINNO, SHINSOO };

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
	StatBlock stats;
	statusType statsPoint;

	PlayerCharacter() = delete;
	PlayerCharacter(const PlayerCharacter&) = delete;
	PlayerCharacter(const PlayerCharacter&&) = delete;

public:
	const void DisplayCharacter() const noexcept override;
	PlayerCharacter(std::string name,KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX);

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

	const equipmentType MaxAttack() const;
	const equipmentType MinAttack() const;
	const equipmentType MaxHealthPoint() const;
	const equipmentType MaxDefense() const;

};


