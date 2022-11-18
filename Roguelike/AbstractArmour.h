#pragma once
#include "AbstractItem.h"
class AbstractArmour : public AbstractItem
{
public:
	~AbstractArmour() {};
	sf::Vector2f GenerateRandomPosition()
	{
		int randomeX = rand() % 20 + 3;
		int randomeY = rand() % 20 + 3;

		return sf::Vector2f(randomeX, randomeY) * float(G_CELL_SIZE);
	};

	int GetArmour()
	{
		if (m_rarity > 3)
		{
			return m_armourClass * m_rarity / 2;
		}
		else
		{
			return m_armourClass;
		}
	};
protected:

	int m_armourClass = 0;
	Armours m_armourType;
};