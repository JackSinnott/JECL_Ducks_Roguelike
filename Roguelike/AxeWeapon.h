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

		m_itemTexture = TextureManager::Acquire("./ASSETS/IMAGES/Items/Weapons/Axe.png");
		m_itemSprite.setTexture(*m_itemTexture);
		//m_itemSprite.setOrigin(G_CELL_SIZE / 2.0f, G_CELL_SIZE / 2.0f);

		m_itemSprite.setPosition(10 * float(G_CELL_SIZE), 10 * float(G_CELL_SIZE));
		m_itemSprite.setScale(0.5f, 0.5f);
		SetType();
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
