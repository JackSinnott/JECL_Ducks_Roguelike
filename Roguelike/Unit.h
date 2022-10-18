#ifndef UNIT_H
#define UNIT_H

#include <cstddef>
#include "Grid.h"

class Unit
{
	friend class Grid;

public:
	Unit(Grid* grid, double x, double y);
	void move(double x, double y);

private:
	double _x, _y;
	Grid* _grid;

	Unit* _prev;
	Unit* _next;
};
#endif // !UNIT_H
