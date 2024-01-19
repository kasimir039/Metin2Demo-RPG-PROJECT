#include "StatBlock.h"

StatBlock::StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX)
	: _vit(VIT),_int(INT),_str(STR),_dex(DEX)
{

	CalculateAllPoint();
	CalculateMaxAllPoint();
}

const statusType StatBlock::GetVit() const noexcept { return _vit; }
const statusType StatBlock::GetInt() const noexcept { return _int; }
const statusType StatBlock::GetStr() const noexcept { return _str; }
const statusType StatBlock::GetDex() const noexcept { return _dex; }
const statusType StatBlock::GetMaxVit() const noexcept { return MAXVIT; }
const statusType StatBlock::GetMaxInt() const noexcept { return MAXINT; }
const statusType StatBlock::GetMaxStr() const noexcept { return MAXSTR; }
const statusType StatBlock::GetMaxDex() const noexcept { return MAXDEX; }
const statusType StatBlock::GetHealthPoint() const noexcept { return healthPoint; }
const statusType StatBlock::GetIntelligencePoint() const noexcept { return intelligencePoint; }
const statusType StatBlock::GetStrengthPoint() const noexcept { return strengthPoint; }
const statusType StatBlock::GetDexPoint() const noexcept { return durabilityPoint; }
const statusType StatBlock::GetMaxHealthPoint() const noexcept { return maxHealthPoint; }
const statusType StatBlock::GetMaxIntelligencePoint() const noexcept { return maxIntelligencePoint; }
const statusType StatBlock::GetMaxStrengthPoint() const noexcept { return maxStrengthPoint; }
const statusType StatBlock::GetMaxDexPoint() const noexcept { return maxDurabilityPoint; }

void StatBlock::SetVit(statusType value) 
{
	if (value < 1)
		return;

	_vit = value; 

}
void StatBlock::SetInt(statusType value)
{ 
	if (value < 1)
		return;

	_int = value; 
}
void StatBlock::SetStr(statusType value)
{
	if (value < 1)
		return;

	_str = value;
}
void StatBlock::SetDex(statusType value)
{ 
	if (value < 1)
		return;

	_dex = value;
}

void StatBlock::SetHealthPoint(statusType value)
{

	const auto maxHp = GetMaxHealthPoint();

	if (value > maxHp) 
	{
		healthPoint = maxHp;
	}
	else
	{
		healthPoint = value;
	}


}

const void StatBlock::CalculateAllPoint() noexcept {
	
	CalculateHealthPoint();
	CalculateIntelligencePoint();
	CalculateStrengthPoint();
	CalculateDexPoint();


}

const void StatBlock::CalculateMaxAllPoint() noexcept {

	CalculateMaxHealthPoint();
	CalculateMaxIntelligencePoint();
	CalculateMaxStrengthPoint();
	CalculateMaxDexPoint();

}

const void StatBlock::CalculateHealthPoint() noexcept
{
	healthPoint = (_vit * POINT) / 2u;

}
const void StatBlock::CalculateIntelligencePoint() noexcept
{
	intelligencePoint = (_int * POINT) / 2u;

}
const void StatBlock::CalculateStrengthPoint() noexcept
{
	strengthPoint = (_str * POINT) / 2u;

}
const void StatBlock::CalculateDexPoint() noexcept
{
	durabilityPoint = (_dex * POINT) / 2u;

}

const void StatBlock::CalculateMaxHealthPoint() noexcept
{
	maxHealthPoint = healthPoint;

}
const void StatBlock::CalculateMaxIntelligencePoint() noexcept
{
	maxIntelligencePoint = intelligencePoint;
}
const void StatBlock::CalculateMaxStrengthPoint() noexcept
{
	maxStrengthPoint = strengthPoint;

}

const void StatBlock::CalculateMaxDexPoint() noexcept
{
	maxDurabilityPoint = durabilityPoint;

}