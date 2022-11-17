#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "SFML/Graphics.hpp"
class Grid
{
public:
	Grid(int t_x, int t_y);
	inline ~Grid() {};
private:
	int x = 0;
	int y = 0;

	sf::VertexArray lines;

};

#endif // !GRID_H
