#include "Tile.h"
#include <iostream>

std::unordered_map<TileType, sf::IntRect> Tile::m_rects = std::unordered_map<TileType, sf::IntRect>(); // initialize

/// <summary>
/// Default Constructor.
/// </summary>
Tile::Tile() :
	m_currentType(TileType::UNUSED)
{
	if (m_rects.size() == 0)
	{
		m_rects.try_emplace(TileType::UNUSED, sf::IntRect{ 0,0,0,0 });
		m_rects.try_emplace(TileType::GROUND, sf::IntRect{ 0,0,32,32 });
		m_rects.try_emplace(TileType::VERTICAL_WALL, sf::IntRect{ 32,0,32,32 });
		m_rects.try_emplace(TileType::HORIZONTAL_WALL, sf::IntRect{ 64,0,32,32 });
		m_rects.try_emplace(TileType::UPPER_CORNER, sf::IntRect{ 0,32,32,32 });
		m_rects.try_emplace(TileType::LOWER_CORNER, sf::IntRect{ 32,32,32,32 });
		m_rects.try_emplace(TileType::INSIDE_WALL, sf::IntRect{ 64,32,32,32 });

	}

	m_hasItem = false;
}

/// <summary>
/// Sets up the values inside Tile, such as its appearance and translation.
/// </summary>
/// <param name="t_tex">The texture of the tile.</param>
/// <param name="t_pos">The position of the tile.</param>
/// <param name="t_offset">The offset the tile should have to the Grid.</param>
/// <param name="t_type">The type of tile it is, determining whether it's passable.</param>
void Tile::setup(std::shared_ptr<sf::Texture>& t_tex, sf::Vector2f t_pos, sf::Vector2f t_offset, TileType t_type)
{
	m_tile.setOrigin(16.f, 16.f);
	m_tile.setTexture(*t_tex);
	m_tile.setPosition((t_pos + sf::Vector2f(16.f, 16.f)) + t_offset);
	// flips sprites so we have right and left walls
	if ((t_pos + sf::Vector2f(16.f, 16.f)).x < 400)
		m_tile.scale(-1.f, 1);
	m_currentType = t_type;
	m_tile.setTextureRect(m_rects.at(t_type));
	// Keeps our ground textures from looking stale and boring by adding some noise to them
	if (m_currentType == TileType::GROUND)
	{
		int rotation = rand() % 4; // 0-3
		m_tile.setRotation(90 * rotation);
	}
}

/// <summary>
/// Draws the tile out onto the SFML screen.
/// </summary>
/// <param name="t_target">Where to draw the Tile.</param>
/// <param name="t_state">The state in which to draw the Tile.</param>
void Tile::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	t_target.draw(m_tile, t_state);
}

/// <summary>
/// Sets up the rows and columns this Tile occupies, for easy returns later.
/// </summary>
void Tile::setGridPosition()
{
	row = m_tile.getPosition().x / G_CELL_SIZE;
	col = m_tile.getPosition().y / G_CELL_SIZE;
}

bool Tile::TileOccupied()
{
	return m_hasItem;
}

void Tile::ToggleTileOccupied()
{
	m_hasItem = !m_hasItem;
}
