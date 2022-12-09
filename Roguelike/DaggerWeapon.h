#pragma once
#include "AbstractWeapon.h"
class DaggerWeapon : public AbstractWeapon
{
public:
	/// <summary>
	/// Constructor for setting up the weapon and its basics
	/// </summary>
	/// <param name="t_weaponType"></param>
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
	/// Override function that returns the damage
	/// </summary>
	/// <returns></returns>
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

