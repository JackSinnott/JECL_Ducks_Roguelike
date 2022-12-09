#pragma once
#include "AbstractPotion.h"

class StrengthPotion : public AbstractPotion
{
public:
	/// <summary>
	/// Sets up the potion type, how powerful it is as well as its basics
	/// </summary>
	/// <param name="t_potionType"></param>
	StrengthPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_strength = 2 + rand() % 10;

		SetupBasics();
		SetType();
	};


	/// <summary>
	/// And overrided function that returns the strenght effect
	/// </summary>
	/// <returns></returns>
	int UseEffect() override
	{
		return m_strength;
	}

private:
	int m_strength = 0;//The strenght modifier on how strong the potion is
};
