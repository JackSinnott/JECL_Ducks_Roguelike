#pragma once
#include "AbstractArmour.h"

/// <summary>
/// The Heavy armour, the strongest of the three #Armours the Player can wear.
/// </summary>

class HeavyArmour : public AbstractArmour
{
public:
	/// <summary>
	/// Overloaded constructor of the class.
	/// Sets the armour type, armour class and rarity to match the #Heavy enum.
	/// </summary>
	/// <param name="t_armourType">The armour type - in this case, the #Heavy armour.</param>
	HeavyArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 5;
		m_rarity = rand() % 10 + 1;

		SetupBasics();
		SetType();
	};
};
