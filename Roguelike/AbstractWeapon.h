#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "TextureManager.h"
class AbstractWeapon
{
public:
	~AbstractWeapon() {};
	virtual int GetDamage() = 0; //Returns the damage of the weapon

	void draw(sf::RenderWindow& t_window) { t_window.draw(m_weaponSprite); };
protected:
	std::shared_ptr<sf::Texture> m_weaponTexture;
	sf::Sprite m_weaponSprite;
	int m_damage;
	int m_rarity;
	Weapons m_weaponType;
	//Should this even be here?
	//int m_damage; //How much damage the weapon does.
	//int m_rarity; //How rare the weapon is. High rarity increases damage. Should be randomised.
};

