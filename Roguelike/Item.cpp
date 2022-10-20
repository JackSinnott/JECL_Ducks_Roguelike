#include "Item.h"

Item::Item(std::string t_itemImageName, sf::Vector2f t_position, int t_rarity)
{

	if (!m_itemTexture.loadFromFile("./ASSETS/IMAGES/" + t_itemImageName))
	{
		std::cout << "This image file could not be loaded: " << t_itemImageName << std::endl;
	}

	m_itemSprite.setPosition(t_position);
	m_itemSprite.setTexture(m_itemTexture);
	m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width / 2, m_itemSprite.getTextureRect().height / 2);
	m_rarity = t_rarity;
	

}

Item::~Item()
{

}

void Item::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_itemSprite);
}
