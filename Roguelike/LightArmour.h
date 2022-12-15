#pragma once
#include "AbstractArmour.h"

/// <summary>
/// The Light armour, the weakest of the three #Armours the Player can wear.
/// </summary>

class LightArmour : public AbstractArmour
{
public:
	/// <summary>
	/// Overloaded constructor of the class.
	/// Sets the armour type, armour class and rarity to match the #Light enum.
	/// </summary>
	/// <param name="t_armourType">The armour type - in this case, the #Light armour.</param>
	LightArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 5;
		m_rarity = rand() % 10+1;

		SetupBasics();
		SetType();
	};
};