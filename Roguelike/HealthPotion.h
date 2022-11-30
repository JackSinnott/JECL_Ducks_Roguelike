#pragma once
#include "AbstractPotion.h"

class HealthPotion : public AbstractPotion
{
public:
	HealthPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_healing = 5 + rand() % 10;

		SetupBasics();

		SetType();
	};

	int GetHealing()
	{
		return m_healing;
	}

private:
	int m_healing = 0;
};
