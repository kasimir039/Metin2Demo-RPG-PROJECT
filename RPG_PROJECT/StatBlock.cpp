#include "StatBlock.h"

StatBlock::StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX)
	: health(VIT),intelligence(INT),strength(STR),durability(DEX)
{
	healthPoint = 0u;
	intelligencePoint = 0u;
	strengthPoint = 0u;
	durabilityPoint = 0u;


	CalculateAllPoint();
}

const statusType StatBlock::GetHealth() const noexcept { return health; }
const statusType StatBlock::GetIntelligence() const noexcept { return intelligence; }
const statusType StatBlock::GetStrength() const noexcept { return strength; }
const statusType StatBlock::GetDurability() const noexcept { return durability; }
const statusType StatBlock::GetHealthPoint() const noexcept{ return healthPoint; }
const statusType StatBlock::GetIntelligencePoint() const noexcept { return intelligencePoint; }
const statusType StatBlock::GetStrengthPoint() const noexcept { return strengthPoint; }
const statusType StatBlock::GetDurabilityPoint() const noexcept { return durabilityPoint; }

void StatBlock::SetHealth(statusType value) {health = value; }
void StatBlock::SetIntelligence(statusType value){ intelligence = value; }
void StatBlock::SetStrength(statusType value){strength = value; }
void StatBlock::SetDurability(statusType value){ durability = value; }



const void StatBlock::CalculateAllPoint() noexcept {
	healthPoint = (health * POINT) / 2u;
	intelligencePoint = (intelligence * POINT) / 2u;
	strengthPoint = (strength * POINT) / 2u;
	durabilityPoint = (durability * POINT) / 2u;


}
const void StatBlock::CalculateHealthPoint() noexcept
{
	healthPoint = (health * POINT) / 2u;
	
}
const void StatBlock::CalculateIntelligencePoint() noexcept
{
	intelligencePoint = (intelligence * POINT) / 2u;
}
const statusType StatBlock::CalculateStrengthPoint() noexcept
{
	return strengthPoint = (strength * POINT) / 2u;
	
}

const void StatBlock::CalculateDurabilityPoint() noexcept
{
	durabilityPoint = (durability * POINT) / 2u;

}
