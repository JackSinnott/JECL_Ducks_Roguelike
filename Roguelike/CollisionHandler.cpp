#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(sf::Vector2i(t_playerPos)) : m_playerPos(t_playerPos)
{
	m_surroundingTiles.push_back(sf::Vector2i(m_playerPos.x - 1, m_playerPos.y));
	m_surroundingTiles.push_back(sf::Vector2i(m_playerPos.x + 1, m_playerPos.y));
	m_surroundingTiles.push_back(sf::Vector2i(m_playerPos.x, m_playerPos.y - 1));
	m_surroundingTiles.push_back(sf::Vector2i(m_playerPos.x, m_playerPos.y + 1));

	int test = 1;
	for (sf::Vector2i pos : m_surroundingTiles)
	{
		std::cout << "tile surrounding player at " << test << " : " << pos.x << "," << pos.y << "\n";
	}
}

bool CollisionHandler::checkCollisonWithWall()
{
	return false;
}
