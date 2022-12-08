#pragma once
#include "AbstractWeapon.h"
class SwordWeapon : public AbstractWeapon
{
public:
	/// <summary>
	/// Constructor for setting up the weapon and its basics
	/// </summary>
	/// <param name="t_weaponType"></param>
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
	/// Override function that returns the damage
	/// </summary>
	/// <returns></returns>
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