#pragma once
#include "StatBlock.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Warrior.h"
#include "Sura.h"
#include <memory>
#include <vector>

enum  CHARACTER { WARRIOR = 1, SURA, SHAMAN, ASSASSIN };
enum  KINGDOM  { CHUNJO = 1, JINNO, SHINSOO };
enum   STATS  { VIT = 1, INT, STR, DEX };


class PlayerCharacter final : public Player
{
private:
	bool CheckLevel();
	void IncreaseStats();

	void ChooseWarriorSkills();
	void ChooseSuraSkills();

	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;
	StatBlock* stats = nullptr;
	Warrior warrior;
	Sura sura;

	std::string characterName;
	KINGDOM kingdom;
	CHARACTER characterType;
	expType experience;
	expType requiredExperience;
	levelType level;
	statusType statsPoint;
	skillType skillScore;

	bool checkSkill;
	static constexpr size_t maxNameLength = 12;
	static constexpr levelType maxLevel = 99u;


public:

	PlayerCharacter(std::string_view name,CHARACTER character,KINGDOM kingdom,statusType VIT, statusType INT, statusType STR, statusType DEX);


	~PlayerCharacter() override;

	//Getters
	 std::string GetCharacterName() const noexcept;
	 std::string GetKingdom() const noexcept;
	 expType GetExp() const noexcept;
	 expType GetRequiredExp() const noexcept;
	 levelType GetLevel() const noexcept;
	 statusType GetStatsPoint() const noexcept;
	
	//Functions
	void DisplayCharacter() noexcept override;
	void GainExperience(expType exp);
	void EquipWeapon(Weapon* weapon);
	void EquipArmor(Armor* armor);
	void TakeDamage(statusType damage);
	void IncreaseHealth(statusType value);
	void ChooseSkills();
	void SetCheckSkills(bool value);

	 void DisplayWeapons() const;
	 void DisplayArmor() const;
	 equipmentType MaxWeaponAttack();
	 equipmentType MinWeaponAttack();
	 equipmentType MaxArmorHealthPoint();
	 equipmentType MaxArmorDefense();

	//Warrior
	void UpgradeWarriorBodyAbilities();
	void UpgradeWarriorMentalAbilities();

	void GetWarriorBodySkills() const noexcept;
	void GetWarriorMentalSkills() const noexcept;

	 bool UseAuraOfTheSword()const;
	 bool UseBerserk()const;
	 bool UseDash()const;
	 bool UseSwordSpin()const;
	 bool UseThreeWayCut()const;

	 bool UseStrongBody()const;
	 bool UseSpiritStrikeWarrior()const;
	 bool UseBash()const;
	 bool UseStump()const;
	 bool UseSwordStrike()const;

	//Sura
	void UpgradeSuraBlackMagicSkills();
	void UpgradeSuraWeaponarySkills();

	void GetSuraBlackMagicSkills() const;
	void GetSuraWeaponarySkills() const;

	 bool UseDarkOrb()const;
	 bool UseDarkProtection() const;
	 bool UseDarkStrike()const;
	 bool UseFlameSpirit()const;
	 bool UseFlameStrike()const;
	 bool UseSpiritStrikeSura()const;

	 bool UseDispel()const;
	 bool UseDragonSwirl()const;
	 bool UseEnchantedArmour()const;
	 bool UseEnchantedBlade()const;
	 bool UseFear()const;
	 bool UseFingerStrike()const;

	PlayerCharacter() = default;

};


