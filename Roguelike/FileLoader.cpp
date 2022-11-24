#include "FileLoader.h"

FileLoader::FileLoader(Grid& t_grid) : m_gridData(t_grid)
{
	srand(time(NULL));
}

void FileLoader::Load()
{
	int xDis = roomCount % 3;
	int yDis = roomCount / 3;
	int room_id;

	sf::Vector2f addedPos = sf::Vector2f(xDis * G_ROOM_ROWS * G_CELL_SIZE, yDis * G_ROOM_COLS * G_CELL_SIZE);

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
					// Pass info to grid (alllllll the tiles)

					m_gridData.setUpRoom(sf::Vector2f(cell % G_ROOM_ROWS, cell / G_ROOM_ROWS) + addedPos,
						static_cast<TileType>(std::stoi(&type.at(i))), room_id, row , col); // convert the character to an int and static cast that to a cell type
					
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

		//
	}
	else
	{
		std::cout << "uh oh \n";
	}
	level.close();

	roomCount += 1;
}

sf::Vector2f FileLoader::PlaceRoom()
{
	return sf::Vector2f{};
}
