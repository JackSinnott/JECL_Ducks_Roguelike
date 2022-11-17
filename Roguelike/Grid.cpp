#include "Grid.h"
#include "Globals.h"

Grid::Grid(int t_x, int t_y) : x(t_x), y(t_y)
{
	for (int i = 0; i < G_MAP_COLS; i++)
	{
		for (int k = 0; k < G_MAP_ROWS; k++)
		{
			x = k * G_CELL_SIZE;
			y = i * G_CELL_SIZE;

			std::cout << "x: " << x << " Y: " << y << "\n";
		}
	}
}
