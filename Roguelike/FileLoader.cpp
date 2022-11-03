#include "FileLoader.h"

FileLoader::FileLoader(GameData& t_ld) :
	m_levelData(t_ld)
{
	srand(time(NULL));
}

void FileLoader::Load(int t_level)
{
	// Generate Number of rooms

	std::vector<int> madeRooms;

	int roomCap = (rand() % 4) + 3;

	// find which rooms will be added
	while (madeRooms.size() < roomCap)
	{
		int placedRoom = rand() % 9;

		if (std::find(madeRooms.begin(), madeRooms.end(), placedRoom) != madeRooms.end())
		{
			continue;
		}

		madeRooms.push_back(placedRoom);
	}

	// GenerateRandom Level Number (which level file will get loaded)

	int loadedLevelNum;

	for (int roomType : madeRooms)
	{
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
						m_levelData.setTile(cell % G_MAP_ROWS, cell / G_MAP_ROWS, static_cast<CellType>(std::stoi(&type.at(i))), roomType); // convert the character to an int and static cast that to a cell type
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
}