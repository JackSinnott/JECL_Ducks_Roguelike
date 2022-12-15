#pragma once
#include "AbstractPotion.h"

/// <summary>
/// The health potion that derives from AbstractPotion. When used, it recovers the Player's health.
/// </summary>

class HealthPotion : public AbstractPotion
{
public:

	/// <summary>
	/// Sets up the potion type, how powerful it is, as well as its basics, such as it's texture and scale.
	/// </summary>
	/// <param name="t_potionType">The type of potion it is - in this case, #Health.</param>
	HealthPotion(Potions t_potionType)
	{
		SetPotionType(t_potionType);
		m_healing = 5 + rand() % 10;

		SetupBasics();
		SetType();
	};

	/// <summary>
	/// And overrided function that returns the health effect.
	/// </summary>
	/// <returns>The amount healed to the Player.</returns>
	int UseEffect() override
	{
		return m_healing;
	}


private:

	///How much the potion will heal for when used.
	int m_healing = 0;
};
