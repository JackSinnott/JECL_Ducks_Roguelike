#include "Grid.h"

Grid::Grid() : m_links(sf::Lines)
{
    // Clear the grid.
    for (int x = 0; x < NUM_CELLS; x++)
    {
        for (int y = 0; y < NUM_CELLS; y++)
        {
            _cells[x][y] = NULL;
        }
    }
}

void Grid::add(Unit* unit)
{
    // Determine which grid cell it's in.
    int cellX = (int)(unit->_x / Grid::CELL_SIZE);
    int cellY = (int)(unit->_y / Grid::CELL_SIZE);

    // Add to the front of list for the cell it's in.
    unit->_prev = NULL;
    unit->_next = _cells[cellX][cellY];
    _cells[cellX][cellY] = unit;

    if (unit->_next != NULL)
    {
        unit->_next->_prev = unit;
    }
}

void Grid::move(Unit* unit, double x, double y)
{
    // See which cell it was in.
    int oldCellX = (int)(unit->_x / Grid::CELL_SIZE);
    int oldCellY = (int)(unit->_y / Grid::CELL_SIZE);

    // See which cell it's moving to.
    int cellX = (int)(x / Grid::CELL_SIZE);
    int cellY = (int)(y / Grid::CELL_SIZE);

    unit->_x = x;
    unit->_y = y;

    // If it didn't change cells, we're done.
    if (oldCellX == cellX && oldCellY == cellY) return;

    // Unlink it from the list of its old cell.
    if (unit->_prev != NULL)
    {
        unit->_prev->_next = unit->_next;
    }

    if (unit->_next != NULL)
    {
        unit->_next->_prev = unit->_prev;
    }

    // If it's the head of a list, remove it.
    if (_cells[oldCellX][oldCellY] == unit)
    {
        _cells[oldCellX][oldCellY] = unit->_next;
    }

    // Add it back to the grid at its new cell.
    add(unit);
}