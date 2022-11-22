#ifndef GLOBALS_H
#define GLOBALS_H


#include <SFML/Graphics.hpp>

enum class Gamestate
{
	MainMenu,
	PauseMenu,
	Options,
	Gameplay,
	GameOver
};
extern Gamestate m_gamestate;

enum class EnemyType
{
	Bat,
	Rat
};


enum class Weapons
{
	Sword,
	Axe,
	Dagger
};

enum class Armours
{
	Light,
	Medium,
	Heavy
};


enum class Potions
{
	Health,
	Strength,
	Speed
};

enum class Scrolls
{
	Fireball,
	Shield,
	Teleportation
};

unsigned const int G_VIEW_WIDTH = 800;
unsigned const int G_VIEW_HEIGTH = 600;

//unsigned int Music_volume;
//unsigned int SFX_volume;
//unsigned int SFX_Walking_Volume;

/// <summary>
/// Might be used later
/// </summary>
unsigned const int G_MAP_ROWS = 25;
unsigned const int G_MAP_COLS = 20;
unsigned const int G_CELL_SIZE = 32;
//unsigned const int MAP_WIDTH = MAP_COLS * CELL_SIZE;
//unsigned const int MAP_HEIGTH = MAP_ROWS * CELL_SIZE ;

#endif // !GLOBALS_H

