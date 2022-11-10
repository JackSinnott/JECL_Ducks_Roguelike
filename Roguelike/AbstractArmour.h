#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "TextureManager.h"

class AbstractArmour
{
public:
	~AbstractArmour() {};
	virtual int GetArmour() = 0;

	void draw(sf::RenderWindow& t_window) { t_window.draw(m_armourSprite); };
protected:
	std::shared_ptr<sf::Texture> m_weaponTexture;
	sf::Sprite m_armourSprite;
	int m_armourClass;
	int m_rarity;
	Armours m_armourType;
};