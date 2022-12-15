#pragma once
#include "AbstractWeapon.h"

/// <summary>
/// The Dagger weapon, the weakest of the three #Weapons the Player can use.
/// </summary>

class DaggerWeapon : public AbstractWeapon
{
public:
	/// <summary>
	/// Constructor for setting up the weapon and its basics.
	/// </summary>
	/// <param name="t_weaponType">The weapon type - in this case, the #Dagger.</param>
	DaggerWeapon(Weapons t_weaponType)
	{
		m_weaponType = t_weaponType;
		m_damage = 2;
		m_rarity = 1;

		m_rarity += rand() % 10;

		SetupBasics();
		SetType();
	};

	/// <summary>
	/// Override function that returns the damage caused by the dagger.
	/// </summary>
	/// <returns>The damage as an integer.</returns>
	int GetDamage() override
	{
		if (m_rarity > 5)
		{
			return m_damage * 2;
		}
		else
		{
			return m_damage;
		}

	};
};

