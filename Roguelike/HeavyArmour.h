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

		m_itemTexture = TextureManager::Acquire(MISSINGTEXTURE);
		m_itemSprite.setTexture(*m_itemTexture);
		m_itemSprite.setOrigin(G_CELL_SIZE / 2.0f, G_CELL_SIZE / 2.0f);

		m_itemSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
			G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_itemSprite.setScale(0.5f, 0.5f);
	};

private:

};
