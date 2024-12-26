#include "StatBlock.h"

StatBlock::StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX)
	: _vit(VIT),_int(INT),_str(STR),_dex(DEX)
{

	CalculateAllPoint();
	CalculateMaxAllPoint();
}

 statusType StatBlock::GetVit() noexcept { return _vit; }
 statusType StatBlock::GetInt() noexcept { return _int; }
 statusType StatBlock::GetStr() noexcept { return _str; }
 statusType StatBlock::GetDex() noexcept { return _dex; }
 statusType StatBlock::GetMaxVit() const noexcept { return MAXVIT; }
 statusType StatBlock::GetMaxInt() const noexcept { return MAXINT; }
 statusType StatBlock::GetMaxStr() const noexcept { return MAXSTR; }
 statusType StatBlock::GetMaxDex() const noexcept { return MAXDEX; }
 statusType StatBlock::GetHealthPoint() const noexcept { return healthPoint; }
 statusType StatBlock::GetIntelligencePoint() const noexcept { return intelligencePoint; }
 statusType StatBlock::GetStrengthPoint() const noexcept { return strengthPoint; }
 statusType StatBlock::GetDexPoint() const noexcept { return durabilityPoint; }
 statusType StatBlock::GetMaxHealthPoint() const noexcept { return maxHealthPoint; }
 statusType StatBlock::GetMaxIntelligencePoint() const noexcept { return maxIntelligencePoint; }
 statusType StatBlock::GetMaxStrengthPoint() const noexcept { return maxStrengthPoint; }
 statusType StatBlock::GetMaxDexPoint() const noexcept { return maxDurabilityPoint; }

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

void StatBlock::SetIntelligencePoint(statusType value)
{

	const auto maxInt = GetMaxIntelligencePoint();

	if (value > maxInt)
	{
		intelligencePoint = maxInt;
	}
	else
	{
		intelligencePoint = value;
	}

}

void StatBlock::SetStrengthPoint(statusType value) 
{


	const auto maxStr = GetMaxStrengthPoint();

	if (value > maxStr)
	{
		strengthPoint = maxStr;
	}
	else
	{
		strengthPoint = value;
	}

}

void StatBlock::SetDurabilityPoint(statusType value)
{

	const auto maxDex = GetMaxDexPoint();

	if (value > maxDex)
	{
		strengthPoint = maxDex;
	}
	else
	{
		strengthPoint = value;
	}

}

 void StatBlock::CalculateAllPoint() noexcept {
	
	CalculateHealthPoint();
	CalculateIntelligencePoint();
	CalculateStrengthPoint();
	CalculateDexPoint();


}

 void StatBlock::CalculateMaxAllPoint() noexcept {

	CalculateMaxHealthPoint();
	CalculateMaxIntelligencePoint();
	CalculateMaxStrengthPoint();
	CalculateMaxDexPoint();

}

 void StatBlock::CalculateHealthPoint() noexcept
{
	healthPoint = (_vit * POINT) / 2u;

}
 void StatBlock::CalculateIntelligencePoint() noexcept
{
	intelligencePoint = (_int * POINT) / 2u;

}
 void StatBlock::CalculateStrengthPoint() noexcept
{
	strengthPoint = (_str * POINT) / 2u;

}
 void StatBlock::CalculateDexPoint() noexcept
{
	durabilityPoint = (_dex * POINT) / 2u;

}

 void StatBlock::CalculateMaxHealthPoint() noexcept
{
	maxHealthPoint = healthPoint;

}
 void StatBlock::CalculateMaxIntelligencePoint() noexcept
{
	maxIntelligencePoint = intelligencePoint;
}
 void StatBlock::CalculateMaxStrengthPoint() noexcept
{
	maxStrengthPoint = strengthPoint;

}

 void StatBlock::CalculateMaxDexPoint() noexcept
{
	maxDurabilityPoint = durabilityPoint;

}