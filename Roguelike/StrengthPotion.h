#pragma once
#include "AbstractPotion.h"

class StrengthPotion : public AbstractPotion
{
public:
	StrengthPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_strength = 2 + rand() % 10;
	};

	int GetStrength()
	{
		return m_strength;
	}

private:
	int m_strength = 0;
};
