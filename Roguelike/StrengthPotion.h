#pragma once
#include "AbstractPotion.h"

/// <summary>
/// The strength potion that derives from AbstractPotion. When used, it modifies the strength stat of Player, allowing them to do more damage.
/// </summary>

class StrengthPotion : public AbstractPotion
{
public:
	/// <summary>
	/// Sets up the potion type, how powerful it is as well as its basics, such as it's texture and scale.
	/// </summary>
	/// <param name="t_potionType">The type of potion it is - in this case, #Strength.</param>
	StrengthPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_strength = 2 + rand() % 10;

		SetupBasics();
		SetType();
	};


	/// <summary>
	/// And overrided function that returns the strength effect.
	/// </summary>
	/// <returns>The added strength from using the potion.</returns>
	int UseEffect() override
	{
		return m_strength;
	}

private:

	///The strength modifier on how strong the potion is, and how much strength it will give the Player when used.
	int m_strength = 0;
};
