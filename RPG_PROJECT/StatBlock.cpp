#include "StatBlock.h"

StatBlock::StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX)
	: health(VIT),intelligence(INT),strength(STR),durability(DEX)
{

	CalculateMaxAllPoint();
}

const statusType StatBlock::GetHealth() const noexcept { return health; }
const statusType StatBlock::GetIntelligence() const noexcept { return intelligence; }
const statusType StatBlock::GetStrength() const noexcept { return strength; }
const statusType StatBlock::GetDurability() const noexcept { return durability; }
const statusType StatBlock::GetHealthPoint() const noexcept { return healthPoint; }
const statusType StatBlock::GetIntelligencePoint() const noexcept { return intelligencePoint; }
const statusType StatBlock::GetStrengthPoint() const noexcept { return strengthPoint; }
const statusType StatBlock::GetDurabilityPoint() const noexcept { return durabilityPoint; }

void StatBlock::SetHealth(statusType value) 
{
	if (value < 1)
		return;

	health = value; 

}
void StatBlock::SetIntelligence(statusType value)
{ 
	if (value < 1)
		return;

	intelligence = value; 
}
void StatBlock::SetStrength(statusType value)
{
	if (value < 1)
		return;

	strength = value;
}
void StatBlock::SetDurability(statusType value)
{ 
	if (value < 1)
		return;
	durability = value;
}

void StatBlock::SetHealthPoint(statusType value)
{

	const auto maxHp = CalculateMaxHealthPoint();

	if (value > maxHp) {

		healthPoint = maxHp;
	}
	else {

		healthPoint = value;
	}

}

const void StatBlock::CalculateMaxAllPoint() noexcept {
	healthPoint = (health * POINT) / 2u;
	intelligencePoint = (intelligence * POINT) / 2u;
	strengthPoint = (strength * POINT) / 2u;
	durabilityPoint = (durability * POINT) / 2u;


}
const statusType StatBlock::CalculateMaxHealthPoint() noexcept
{
	return healthPoint = (health * POINT) / 2u;
	
}
const void StatBlock::CalculateMaxIntelligencePoint() noexcept
{
	intelligencePoint = (intelligence * POINT) / 2u;
}
const void StatBlock::CalculateMaxStrengthPoint() noexcept
{
	strengthPoint = (strength * POINT) / 2u;
	
}

const void StatBlock::CalculateMaxDurabilityPoint() noexcept
{
	durabilityPoint = (durability * POINT) / 2u;

}


