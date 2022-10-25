#ifndef GRID_H
#define GRID_H

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Grid
{
private:

public:
	Grid();

	~Grid();

	sf::Vertex m_point;
	sf::VertexArray m_tiles;

	void setup(sf::Vector2f t_pos);
	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;
	sf::Vector2f getPosition();
	void Test();

};

#endif // !GRID_H


