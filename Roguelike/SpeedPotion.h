#pragma once
#include "AbstractPotion.h"

/// <summary>
/// The speed potion that derives from AbstractPotion. When used, it lets the Player do more actions per turn.
/// </summary>

class SpeedPotion : public AbstractPotion
{
public:

	/// <summary>
	/// Sets up the potion type, how powerful it is as well as its basics, such as it's texture and scale.
	/// </summary>
	/// <param name="t_potionType">The type of potion it is - in this case, #Speed.</param>
	SpeedPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_speed = 2 + rand() % 10;

		SetupBasics();
		SetType();
	};


	/// <summary>
	/// An overrided function that returns the speed effect.
	/// </summary>
	/// <returns>The number of extra actions the player can take per turn.</returns>
	int UseEffect() override
	{
		return m_speed;
	}


private:

	///Speed stat of the potion - how many extra actions the player will be able to take.
	int m_speed = 0;
};
