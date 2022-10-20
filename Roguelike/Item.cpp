#include "Item.h"

Item::Item(std::string t_itemImageName, sf::Vector2f t_position, int t_rarity) : m_name(t_itemImageName), m_position(t_position), m_rarity(t_rarity)
{


	m_pTexture = TextureManager::Acquire("./ASSETS/IMAGES/" + t_itemImageName);

	m_itemSprite.setTexture(*m_pTexture);
	m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width / 2, m_itemSprite.getTextureRect().height / 2);
	m_itemSprite.setPosition(t_position.x * (G_CELL_SIZE / 2), t_position.y * G_CELL_SIZE / 2);
	m_itemSprite.setScale(0.5f, 0.5f);
	m_rarity = t_rarity;
}

Item::~Item()
{

}

void Item::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_itemSprite);
}
