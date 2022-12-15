#pragma once
#include "AbstractArmour.h"

/// <summary>
/// The Medium armour, the middle of the three #Armours the Player can wear.
/// </summary>

class MediumArmour : public AbstractArmour
{
public:
	/// <summary>
	/// Overloaded constructor of the class.
	/// Sets the armour type, armour class and rarity to match the #Medium enum.
	/// </summary>
	/// <param name="t_armourType">The armour type - in this case, the #Medium armour.</param>
	MediumArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 10;
		m_rarity = rand() % 10 + 1;
		SetupBasics();
		SetType();
	};
};

