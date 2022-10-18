#include "Unit.h"

Unit::Unit(Grid* grid, double x, double y)
	: _grid(grid),
	_x(x),
	_y(y),
	_prev(NULL),
	_next(NULL)
{
	_grid->add(this);
}

void Unit::move(double x, double y)
{
	_grid->move(this, x, y);
}