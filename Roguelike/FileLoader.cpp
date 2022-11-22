#include "FileLoader.h"

FileLoader::FileLoader(Grid& t_grid) : m_gridData(t_grid)
{
	srand(time(NULL));
}

void FileLoader::Load(int t_level)
{

	int loadedLevelNum;

	loadedLevelNum = (rand() % 7) + 1;

	// load in the level data and setup levelData
	std::ifstream level;
	std::string path = "ASSETS/levels/Level" + std::to_string(loadedLevelNum) + ".txt";
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


					//m_levelData.setTile(cell % G_MAP_ROWS, cell / G_MAP_ROWS, static_cast<CellType>(std::stoi(&type.at(i))), roomType); // convert the character to an int and static cast that to a cell type
					cell++;
				}
			}
		}
	}
	else
	{
		std::cout << "uh oh \n";
	}
	level.close();

	
}
