#pragma once
#include "AbstractWeapon.h"
class AxeWeapon : public AbstractWeapon
{
public:
	int Attack() override 
	{
		if (true)
		{

		}
		else
		{
			return m_damage;
		}

	};
private:
	int m_damage = 5;
	int m_rarity = 0;
};

