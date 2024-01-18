#include "StatBlock.h"

StatBlock::StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX)
	: _vit(VIT),_int(INT),_str(STR),_dex(DEX)
{

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

void StatBlock::SetHealth(statusType value) 
{
	if (value < 1)
		return;

	_vit = value; 

}
void StatBlock::SetIntelligence(statusType value)
{ 
	if (value < 1)
		return;

	_int = value; 
}
void StatBlock::SetStrength(statusType value)
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

	const auto maxHp = CalculateMaxHealthPoint();

	if (value > maxHp) {

		healthPoint = maxHp;
	}
	else {

		healthPoint = value;
	}

}

const void StatBlock::CalculateMaxAllPoint() noexcept {
	healthPoint = (_vit * POINT) / 2u;
	intelligencePoint = (_int * POINT) / 2u;
	strengthPoint = (_str * POINT) / 2u;
	durabilityPoint = (_dex * POINT) / 2u;


}
const statusType StatBlock::CalculateMaxHealthPoint() noexcept
{
	return healthPoint = (_vit * POINT) / 2u;
	
}
const void StatBlock::CalculateMaxIntelligencePoint() noexcept
{
	intelligencePoint = (_int * POINT) / 2u;
}
const void StatBlock::CalculateMaxStrengthPoint() noexcept
{
	strengthPoint = (_str * POINT) / 2u;
	
}

const void StatBlock::CalculateMaxDexPoint() noexcept
{
	durabilityPoint = (_dex * POINT) / 2u;

}


