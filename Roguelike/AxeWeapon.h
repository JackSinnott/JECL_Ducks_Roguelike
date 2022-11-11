#pragma once
#include "AbstractWeapon.h"
class AxeWeapon : public AbstractWeapon
{
public:
	AxeWeapon(Weapons t_weaponType)
	{
		m_weaponType = t_weaponType;
		m_damage = 8;
		m_rarity = 1;

		m_rarity += rand() % 10;

		m_weaponTexture = TextureManager::Acquire("./ASSETS/IMAGES/Items/Weapons/Axe.png");
		m_weaponSprite.setTexture(*m_weaponTexture);
		//m_weaponSprite.setOrigin(m_weaponSprite.getTextureRect().width / 2, m_weaponSprite.getTextureRect().height / 2);
		m_weaponSprite.setOrigin(G_CELL_SIZE/2.0f, G_CELL_SIZE / 2.0f);
		m_weaponSprite.setPosition(G_MAP_ROWS, G_MAP_COLS);
		m_weaponSprite.setScale(0.5f, 0.5f);
	};

	int GetDamage() override 
	{
		if (m_rarity > 5)
		{
			return m_damage * 2;
		}
		else
		{
			return m_damage;
		}

	};
};
