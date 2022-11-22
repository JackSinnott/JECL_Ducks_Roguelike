#include "FileLoader.h"

FileLoader::FileLoader(Grid& t_grid) : m_gridData(t_grid)
{
	srand(time(NULL));
}

void FileLoader::Load(int t_level)
{

	int room_id;

	room_id = (rand() % 7) + 1;

	// load in the level data and setup levelData
	std::ifstream level;
	std::string path = "ASSETS/levels/Level" + std::to_string(room_id) + ".txt";
	level.open(path);

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

					m_gridData.setUpRoom(sf::Vector2f(cell % G_ROOM_ROWS, cell / G_ROOM_ROWS), 
						static_cast<TileType>(std::stoi(&type.at(i))), room_id); // convert the character to an int and static cast that to a cell type
					cell++;
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

	
}
