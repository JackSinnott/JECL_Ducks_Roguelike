#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "LevelLoader.h"
#include <fstream>
#include <iostream>

#include "Globals.h"
#include "Grid.h"

class FileLoader : public LevelLoader
{
public:
	FileLoader(Grid& t_room);

	void Load(int t_level)override;


private:

	Grid& m_gridData;
};

#endif // !FILE_LOADER_H