#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"

class Grid
{
private:
	sf::Vertex m_vertex;

public:
	sf::VertexArray m_links;
	Grid();

};

#endif // !GRID_H


