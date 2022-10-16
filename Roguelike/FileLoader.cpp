#include "FileLoader.h"

FileLoader::FileLoader(GameData& t_ld) :
	m_levelData(t_ld)
{
}

void FileLoader::Load(int t_level)
{
	// load in the level data and setup levelData
	std::ifstream level;
	std::string path = "ASSETS/LEVELS/Level" + std::to_string(t_level) + ".txt";
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
					m_levelData.setTile(cell % 25, cell / 25, static_cast<CellType>(std::stoi(&type.at(i)))); // convert the character to an int and static cast that to a cell type
					cell++;
				}
			}
		}
	}
	level.close();
}