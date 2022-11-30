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

enum class ItemType
{
	Weapon,
	Armour,
	Potion
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

enum class TileType
{
	UNUSED = 0,
	GROUND = 1,
	VERTICAL_WALL = 2,
	HORIZONTAL_WALL = 3,
	UPPER_CORNER = 4,
	LOWER_CORNER = 5,
	INSIDE_WALL = 6
};

unsigned const int G_VIEW_WIDTH = 1800;
unsigned const int G_VIEW_HEIGTH = 900;

//unsigned int Music_volume;
//unsigned int SFX_volume;
//unsigned int SFX_Walking_Volume;

/// <summary>
/// Might be used later
/// </summary>
unsigned const int G_ROOM_ROWS = 25; // Max room row num
unsigned const int G_ROOM_COLS = 20; // Max room col num
unsigned const int G_MAP_ROWS = 75; // Max overall map row num
unsigned const int G_MAP_COLS = 60; // Max overall map col num
unsigned const int G_CELL_SIZE = 32;
//unsigned const int MAP_WIDTH = MAP_ROWS * CELL_SIZE;
//unsigned const int MAP_HEIGTH = MAP_COLS * CELL_SIZE ;

std::string const MISSINGTEXTURE = "./ASSETS/IMAGES/MissingTexture.png";
std::string const ITEMS_TEXTURE = "./ASSETS/IMAGES/tilemap_packed.png";

#endif // !GLOBALS_H

