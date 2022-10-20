#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"
#include "Globals.h"

class Grid
{
private:

public:
	sf::VertexArray m_links;
	Grid();

	void Render(sf::RenderWindow& m_win);

};

#endif // !GRID_H


