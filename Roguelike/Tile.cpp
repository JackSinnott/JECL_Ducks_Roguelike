#include "Tile.h"
#include <iostream>

std::unordered_map<CellType, sf::IntRect> Tile::m_rects = std::unordered_map<CellType, sf::IntRect>(); // initialize

Tile::Tile() :
	m_currentType(CellType::UNUSED),
	m_grid()
{
	if (m_rects.size() == 0)
	{
		m_rects.try_emplace(CellType::UNUSED, sf::IntRect{ 0,0,0,0 });
		m_rects.try_emplace(CellType::GROUND, sf::IntRect{ 0,0,32,32 });
		m_rects.try_emplace(CellType::VERTICAL_WALL, sf::IntRect{ 32,0,32,32 });
		m_rects.try_emplace(CellType::HORIZONTAL_WALL, sf::IntRect{ 64,0,32,32 });
		m_rects.try_emplace(CellType::UPPER_CORNER, sf::IntRect{ 0,32,32,32 });
		m_rects.try_emplace(CellType::LOWER_CORNER, sf::IntRect{ 32,32,32,32 });
		m_rects.try_emplace(CellType::INSIDE_WALL, sf::IntRect{ 64,32,32,32 });
	}
}

void Tile::setup(std::shared_ptr<sf::Texture>& t_tex, sf::Vector2f t_pos, CellType t_type)
{
	m_tile.setTexture(*t_tex);
	m_tile.setOrigin(16.f, 16.f);
	m_tile.setPosition(t_pos + sf::Vector2f(16.f, 16.f));
	// flips sprites so we have right and left walls
	if ((t_pos + sf::Vector2f(16.f, 16.f)).x < 400)
		m_tile.scale(-1.f, 1);
	m_currentType = t_type;
	m_tile.setTextureRect(m_rects.at(t_type));
	// Keeps our ground textures from looking stale and boring by adding some noise to them
	if (m_currentType == CellType::GROUND)
	{
		int rotation = rand() % 4; // 0-3
		m_tile.setRotation(90 * rotation);
	}
	m_grid.setup(t_pos);
	m_grid.getPosition();
	//m_grid.Test();

}

void Tile::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	t_target.draw(m_tile, t_state);
	m_grid.draw(t_target, t_state);
}

sf::Vector2f Tile::getPosition()
{
	std::cout << "position of point: " << m_grid.m_point.position.x << ", " << m_grid.m_point.position.y << "\n";
	return m_grid.getPosition();
}



