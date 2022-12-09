#pragma once
#include "AbstractArmour.h"

class LightArmour : public AbstractArmour
{
public:
	/// <summary>
	/// Default overloaded constructor
	/// Sets the armour type, armour class and rarity
	/// </summary>
	/// <param name="t_armourType"></param>
	LightArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 5;
		m_rarity = rand() % 10+1;

		SetupBasics();
		SetType();
	};
};