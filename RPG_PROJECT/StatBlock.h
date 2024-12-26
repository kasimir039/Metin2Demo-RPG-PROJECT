#pragma once
#include "Types.h"

class StatBlock
{
private:
	
	static constexpr statusType POINT = 5u;
	static constexpr statusType MAXVIT = 90u;
	static constexpr statusType MAXINT = 90u;
	static constexpr statusType MAXSTR = 90u;
	static constexpr statusType MAXDEX = 90u;

	statusType _vit; // VIT
	statusType _int; // INT
	statusType _str; // STR
	statusType _dex; // DEX

	statusType healthPoint; // HP
	statusType intelligencePoint; // SP
	statusType strengthPoint; // AP
	statusType durabilityPoint; //DEF

	statusType maxHealthPoint; 
	statusType maxIntelligencePoint;
	statusType maxStrengthPoint; 
	statusType maxDurabilityPoint; 

public:

	StatBlock(statusType VIT, statusType INT, statusType STR, statusType DEX);

	StatBlock(const StatBlock&) = delete;
	StatBlock(const StatBlock&&) = delete;

	//Getters
	 statusType GetVit() noexcept;
	 statusType GetInt() noexcept;
	 statusType GetStr() noexcept;
	 statusType GetDex() noexcept;

	 statusType GetMaxVit() const noexcept;
	 statusType GetMaxInt() const noexcept;
	 statusType GetMaxStr() const noexcept;
	 statusType GetMaxDex() const noexcept;

	 statusType GetHealthPoint() const noexcept;
	 statusType GetIntelligencePoint() const noexcept;
	 statusType GetStrengthPoint() const noexcept;
	 statusType GetDexPoint() const noexcept;

	 statusType GetMaxHealthPoint() const noexcept;
	 statusType GetMaxIntelligencePoint() const noexcept;
	 statusType GetMaxStrengthPoint() const noexcept;
	 statusType GetMaxDexPoint() const noexcept;

	//Setters
	void SetVit(statusType value);
	void SetInt(statusType value);
	void SetStr(statusType value);
	void SetDex(statusType value);

	void SetHealthPoint(statusType value);
	void SetIntelligencePoint(statusType value);
	void SetStrengthPoint(statusType value);
	void SetDurabilityPoint(statusType value);


	//Functions
	 void CalculateAllPoint() noexcept;
	 void CalculateMaxAllPoint() noexcept;

	 void CalculateHealthPoint() noexcept;
	 void CalculateIntelligencePoint() noexcept;
	 void CalculateStrengthPoint() noexcept;
	 void CalculateDexPoint() noexcept;

	 void CalculateMaxHealthPoint() noexcept;
	 void CalculateMaxIntelligencePoint() noexcept;
	 void CalculateMaxStrengthPoint() noexcept;
	 void CalculateMaxDexPoint() noexcept;



};

