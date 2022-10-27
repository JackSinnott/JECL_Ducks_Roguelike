#include "Grid.h"

Grid::Grid()
{
	m_point.color = sf::Color::Red;
}

Grid::~Grid()
{
}

void Grid::setup(sf::Vector2f t_pos)
{
	m_point.position = t_pos;
	m_tiles.append(m_point);
}

void Grid::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	t_target.draw(m_tiles, t_state);
}




