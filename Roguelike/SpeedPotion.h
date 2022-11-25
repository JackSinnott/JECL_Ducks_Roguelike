#pragma once
#include "AbstractPotion.h"

class SpeedPotion : public AbstractPotion
{
public:
	SpeedPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_speed = 2 + rand() % 10;

		SetupBasics();
		SetType();
	};

	int GetStrength()
	{
		return m_speed;
	}

private:
	int m_speed = 0;
};
