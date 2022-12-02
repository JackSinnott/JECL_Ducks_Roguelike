#pragma once
#include "AbstractPotion.h"

class StrengthPotion : public AbstractPotion
{
public:
	StrengthPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_strength = 2 + rand() % 10;

		SetupBasics();

		SetType();
	};

	int UseEffect() override
	{
		return m_strength;
	}

private:
	int m_strength = 0;
};
