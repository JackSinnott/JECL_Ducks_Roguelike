#ifndef GRID_H
#define GRID_H

#include <cstddef>
#include "Globals.h"
#include "Unit.h"
#include "SFML/Graphics.hpp"

class Unit;
class Grid : public sf::Drawable, public sf::Transformable
{
public:
    Grid();

    static const int NUM_CELLS = 500;
    static const int CELL_SIZE = G_CELL_SIZE;
    void add(Unit* unit);
    void move(Unit* unit, double x, double y);

    sf::Vertex m_vertex;
    sf::VertexArray m_links;
#ifdef DEBUG_INFO
    sf::CircleShape m_debugShow;
#endif // DEBUG_INFO
private:
    Unit* _cells[NUM_CELLS][NUM_CELLS];

};
#endif // !GRID_H
