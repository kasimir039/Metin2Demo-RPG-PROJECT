#pragma once
#include "Types.h"

constexpr statusType POINT = 5;

class StatBlock
{
private:
	statusType _vit; // VIT
	statusType _int; // INT
	statusType _str; // STR
	statusType _dex; // DEX

	statusType healthPoint; // HP
	statusType intelligencePoint; // SP
	statusType strengthPoint; // AP
	statusType durabilityPoint; //DEF

	const statusType MAXVIT = 90u;
	const statusType MAXINT = 90u;
	const statusType MAXSTR = 90u;
	const statusType MAXDEX = 90u;


public:

	StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX);

	//Getters
	const statusType GetVit() const noexcept;
	const statusType GetInt() const noexcept;
	const statusType GetStr() const noexcept;
	const statusType GetDex() const noexcept;
	const statusType GetMaxVit() const noexcept;
	const statusType GetMaxInt() const noexcept;
	const statusType GetMaxStr() const noexcept;
	const statusType GetMaxDex() const noexcept;
	const statusType GetHealthPoint() const noexcept;
	const statusType GetIntelligencePoint() const noexcept;
	const statusType GetStrengthPoint() const noexcept;
	const statusType GetDexPoint() const noexcept;

	//Setters
	void SetHealth(statusType value);
	void SetIntelligence(statusType value);
	void SetStrength(statusType value);
	void SetDex(statusType value);
	void SetHealthPoint(statusType value);
	//void SetIntelligencePoint(statusType value);
	//void SetStrengthPoint(statusType value);
	//void SetDurabilityPoint(statusType value);

	//Functions
	const void CalculateMaxAllPoint() noexcept;
	const statusType CalculateMaxHealthPoint() noexcept;
	const void CalculateMaxIntelligencePoint() noexcept;
	const void CalculateMaxStrengthPoint() noexcept;
	const void CalculateMaxDexPoint() noexcept;

};

