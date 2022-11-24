#pragma once
#include "AbstractWeapon.h"
class SwordWeapon : public AbstractWeapon
{
public:
	SwordWeapon(Weapons t_weaponType)
	{
		m_weaponType = t_weaponType;
		m_damage = 5;
		m_rarity = 1;

		m_rarity += rand() % 10;

		m_itemTexture = TextureManager::Acquire(MISSINGTEXTURE);
		m_itemSprite.setTexture(*m_itemTexture);
		m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width, m_itemSprite.getTextureRect().height);

		m_itemSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
			G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_itemSprite.setScale(0.5f, 0.5f);
	};

	int GetDamage() override
	{
		if (m_rarity > 3)
		{
			return m_damage * m_rarity/2;
		}
		else
		{
			return m_damage;
		}

	};
};