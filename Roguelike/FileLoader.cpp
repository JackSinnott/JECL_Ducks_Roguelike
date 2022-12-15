#include "FileLoader.h"

/// <summary>
/// Overloaded Constructor.
/// </summary>
/// <param name="t_grid">A reference to the Grid in Gameplay.</param>
FileLoader::FileLoader(Grid& t_grid) : m_gridData(t_grid)
{
	srand(time(NULL));
}

/// <summary>
/// Loads a Room out of the level text files.
/// </summary>
/// <param name="t_level">The index of the Room to be loaded.</param>
void FileLoader::Load(int t_level)
{
	room_id += 1; // If this is the same value again the room is discarded

	if (room_id == 8)
		room_id = 1;
	// load in the level data and setup levelData
	std::ifstream m_level;
	std::string path = "ASSETS/levels/Level" + std::to_string(room_id) + ".txt";
	m_level.open(path);
	//std::cout << "current random Number is: " << room_id << "\n";


	int col = 0;
	int row = 0;

	if (m_level.is_open())
	{
		int cell = 0;
		std::string type;
		while (std::getline(m_level, type))
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
		m_level.close();
	}
	else
	{
		std::cout << "uh oh \n";
	}
}
