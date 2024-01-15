#pragma once
#include "Types.h"

constexpr statusType POINT = 5;

class StatBlock
{
private:
	statusType health;
	statusType intelligence;
	statusType strength;
	statusType durability;

	statusType healthPoint;
	statusType intelligencePoint;
	statusType strengthPoint;
	statusType durabilityPoint;


public:

	StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX);

	//Getters
	const statusType GetHealth() const noexcept;
	const statusType GetIntelligence() const noexcept;
	const statusType GetStrength() const noexcept;
	const statusType GetDurability() const noexcept;
	const statusType GetHealthPoint() const noexcept;
	const statusType GetIntelligencePoint() const noexcept;
	const statusType GetStrengthPoint() const noexcept;
	const statusType GetDurabilityPoint() const noexcept;

	//Setters
	void SetHealth(statusType value);
	void SetIntelligence(statusType value);
	void SetStrength(statusType value);
	void SetDurability(statusType value);

	void SetStrengthPoint(statusType value)
	{
		strengthPoint = value;
	}

	//Functions
	const void CalculateAllPoint() noexcept;
	const void CalculateHealthPoint() noexcept;
	const void CalculateIntelligencePoint() noexcept;
	const statusType CalculateStrengthPoint() noexcept;
	const void CalculateDurabilityPoint() noexcept;


};

