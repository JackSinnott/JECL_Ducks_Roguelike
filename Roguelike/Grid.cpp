#include "Grid.h"

Grid::Grid()
{
	for (int x = 1; x <= G_MAP_ROWS; x++)
	{
		for (int y = 1; y <= G_MAP_COLS; y++)
		{
			m_links[x].position = sf::Vector2f{ static_cast<float>(G_CELL_SIZE * y), static_cast<float>(G_CELL_SIZE / y) };
			m_links[x].color = sf::Color{ 255,255,255,32U };
		}
	}
}

void Grid::Render(sf::RenderWindow& m_win)
{
	for (int x = 0; x < G_MAP_ROWS; x++)
	{
		for (int y = 0; y < G_MAP_COLS; y++)
		{
			m_win.draw(m_links);
		}
	}
}
