#pragma once
#include "AbstractWeapon.h"

/// <summary>
/// The Sword weapon, the middle of the three #Weapons the Player can use.
/// </summary>

class SwordWeapon : public AbstractWeapon
{
public:
	/// <summary>
	/// Constructor for setting up the weapon and its basics.
	/// </summary>
	/// <param name="t_weaponType">The weapon type - in this case, the #Sword.</param>
	SwordWeapon(Weapons t_weaponType)
	{
		m_weaponType = t_weaponType;
		m_damage = 5;
		m_rarity = 1;

		m_rarity += rand() % 10;

		SetupBasics();
		SetType();
	};

	/// <summary>
	/// Override function that returns the damage caused by the sword.
	/// </summary>
	/// <returns>The damage as an integer.</returns>
	int GetDamage() override
	{
		if (m_rarity > 3)
		{
			return m_damage * m_rarity/2;
		}
		else
		{
			return m_damage;
		}

	};
};