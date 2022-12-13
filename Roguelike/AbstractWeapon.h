#pragma once
#include "AbstractItem.h"

/// <summary>
/// Abstract Weapon which AxeWeapon, DaggerWeapon and SwordWeapon derive from.
/// </summary>

class AbstractWeapon : public AbstractItem
{
public:

	/// <summary>
	/// Default Class Constructor.
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

	/// <summary>
	/// Default Class Deconstructor.
	/// </summary>
	~AbstractWeapon() {};

	/// <summary>
	/// Sets the type of item it is, as well as assign the weapon's texture.
	/// </summary>
	void SetType() { m_itemType = ItemType::Weapon; m_itemSprite.setTextureRect(m_rects.at(m_weaponType));};


	/// <summary>
	/// Gets the damage of the weapon.
	/// </summary>
	/// <returns>The damage number of the weapon.</returns>
	virtual int GetDamage() { return m_damage; }; //Returns the damage of the weapon

protected:

	///How much damage the weapon does.
	int m_damage = 0; 

	///Texture rect of the sprite.
	static std::unordered_map<Weapons, sf::IntRect> m_rects;

	///The type of weapon it is.
	Weapons m_weaponType = Weapons::Sword;
};

