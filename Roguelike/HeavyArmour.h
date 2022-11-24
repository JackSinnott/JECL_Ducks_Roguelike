#pragma once
#include "AbstractArmour.h"
class HeavyArmour : public AbstractArmour
{
public:
	HeavyArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 5;
		m_rarity = rand() % 10 + 1;

		SetupBasics();
		SetType();
	};
};
