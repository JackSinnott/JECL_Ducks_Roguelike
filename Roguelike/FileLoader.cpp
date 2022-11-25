#include "FileLoader.h"

FileLoader::FileLoader(Grid& t_grid) : m_gridData(t_grid)
{
	srand(time(NULL));
}

void FileLoader::Load(int t_level)
{
	roomCount = t_level;
	int room_id;

	room_id = (rand() % 7) + 1;

	// load in the level data and setup levelData
	std::ifstream level;
	std::string path = "ASSETS/levels/Level" + std::to_string(room_id) + ".txt";
	level.open(path);

	int col = 0;
	int row = 0;

	if (level.is_open())
	{
		int cell = 0;
		std::string type;
		while (std::getline(level, type))
		{
			for (int i = 0; i < type.size(); ++i)
			{
				if (type.at(i) != ' ' && type.at(i) != ',')
				{
					// Pass info to grid (all the tiles)

					m_gridData.setUpRoom(static_cast<TileType>(std::stoi(&type.at(i))), room_id, row , col); // convert the character to an int and static cast that to a cell type
					
					row++;
					cell++;

					if (row >= G_ROOM_ROWS)
					{
						col++;
						row = 0;
					}
				}
			}
		}
	level.close();
	}
	else
	{
		std::cout << "uh oh \n";
	}
}
