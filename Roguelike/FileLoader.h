#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "LevelLoader.h"
#include <fstream>
#include "GameData.h"

class FileLoader : public LevelLoader
{
public:
	FileLoader(GameData& t_gd);

	void Load(int t_level)override;


private:
	GameData& m_levelData;
};

#endif // !FILE_LOADER_H
