#include "CollisionHandler.h"

CollisionHandler::CollisionHandler() 
{
	
}

void CollisionHandler::update(sf::Vector2i(t_playerPos))
{
	if (m_surroundingTiles.size() < 4)
	{
		m_surroundingTiles.push_back(sf::Vector2i(t_playerPos.x - 1, t_playerPos.y));
		m_surroundingTiles.push_back(sf::Vector2i(t_playerPos.x + 1, t_playerPos.y));
		m_surroundingTiles.push_back(sf::Vector2i(t_playerPos.x, t_playerPos.y - 1));
		m_surroundingTiles.push_back(sf::Vector2i(t_playerPos.x, t_playerPos.y + 1));
	}
	int test = 1;
	for (sf::Vector2i pos : m_surroundingTiles)
	{
		//std::cout << "tile surrounding player at " << test << " : " << pos.x << "," << pos.y << "\n";
	}
}

bool CollisionHandler::checkCollisonWithWall(int t_playerRoom)
{

	return false;
}
