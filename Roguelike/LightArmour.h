#pragma once
#include "AbstractArmour.h"

class LightArmour : public AbstractArmour
{
public:
	LightArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 2;
		m_rarity = rand() % 10+1;

		m_armourTexture = TextureManager::Acquire(MISSINGTEXTURE);
		m_armourSprite.setTexture(*m_armourTexture);
		m_armourSprite.setOrigin(G_CELL_SIZE / 2.0f, G_CELL_SIZE / 2.0f);

		m_armourSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
								   G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_armourSprite.setScale(0.5f, 0.5f);
		
	};

	int GetArmour()
	{
		if (m_rarity > 3)
		{
			return m_armourClass * m_rarity/2;
		}
		else
		{
			return m_armourClass;
		}
	};
};