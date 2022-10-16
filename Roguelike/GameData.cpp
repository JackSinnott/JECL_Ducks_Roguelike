#include "GameData.h"

GameData::GameData()
{

	m_pTexture = TextureManager::Acquire("Assets//Images//Level//MapTiles.png");
}

//********************************************************

void GameData::setTile(int row, int col, CellType t_type)
{
	m_data[row][col].setup(m_pTexture, sf::Vector2f{ static_cast<float>(row * 32), static_cast<float>(col * 32) }, t_type);
}

//********************************************************

void GameData::addWalls(std::vector<sf::Sprite*>& t_walls)
{
	for (auto& x : m_data)
		for (auto& tile : x)
			if (tile.getType() != CellType::GROUND && tile.getType() != CellType::UNUSED)
				t_walls.push_back(&tile.getSprite());
}

//********************************************************

void GameData::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	for (auto& row : m_data)
		for (auto& x : row)
			t_target.draw(x, t_state);
}