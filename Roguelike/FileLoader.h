#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "LevelLoader.h"
#include <fstream>
#include <iostream>

#include "Globals.h"
#include "Grid.h"

/// <summary>
/// Child class of LevelLoader, this class loads the Room objects in using the text files in the project folders.
/// </summary>

class FileLoader : public LevelLoader
{
public:
	FileLoader(Grid& t_room);

	void Load(int t_level)override;

private:

	///The Grid - everything loaded here will be passed into this.
	Grid& m_gridData;

	///Keeps track of what rooms have been loaded.
	int room_id = 0;
};

#endif // !FILE_LOADER_H