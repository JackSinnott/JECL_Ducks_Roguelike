#pragma once
#include "AbstractWeapon.h"
class DaggerWeapon : public AbstractWeapon
{
public:
	DaggerWeapon(Weapons t_weaponType)
	{
		m_weaponType = t_weaponType;
		m_damage = 2;
		m_rarity = 1;

		m_rarity += rand() % 10;

		SetupBasics();
		SetType();
	};

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

