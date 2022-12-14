#ifndef LEVEL_lOADER_H
#define LEVEL_LOADER_H

/// <summary>
/// Pure virtual class that's used as a base for FileLoader.
/// </summary>

class LevelLoader
{
public:

	/// <summary>
	/// Pure virtual function that will load a Room out of the level text files in the child class.
	/// </summary>
	/// <param name="t_level">The index of the Room that will be loaded.</param>
	virtual void Load(int t_level) = 0;
};


#endif // !LEVEL_lOADER_H