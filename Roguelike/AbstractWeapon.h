#pragma once

#include "AbstractItem.h"
class AbstractWeapon : public AbstractItem
{
public:
	/// <summary>
	/// Abstract weapon which all weapons derive from
	/// </summary>
	AbstractWeapon()
	{
		if (m_rects.size() == 0)
		{
			m_rects.try_emplace(Weapons::Axe, sf::IntRect{ 160,144,16,16 });
			m_rects.try_emplace(Weapons::Dagger, sf::IntRect{ 112,128,16,16 });
			m_rects.try_emplace(Weapons::Sword, sf::IntRect{ 160,128,16,16 });
		}
	}

	~AbstractWeapon() {};

	/// <summary>
	/// Gets the type of item it is as well as assign the weapon's texture
	/// </summary>
	void SetType() { m_itemType = ItemType::Weapon; m_itemSprite.setTextureRect(m_rects.at(m_weaponType));};


	/// <summary>
	/// Gets the damage of the weapon
	/// </summary>
	/// <returns></returns>
	virtual int GetDamage() { return m_damage; }; //Returns the damage of the weapon

protected:
	int m_damage = 0; //How much damage the weapon does.
	static std::unordered_map<Weapons, sf::IntRect> m_rects; //Texture rect of the sprite
	Weapons m_weaponType;//The type of weapon it is
};

