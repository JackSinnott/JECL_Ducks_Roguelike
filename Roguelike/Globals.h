#ifndef GLOBALS_H
#define GLOBALS_H


#include <SFML/Graphics.hpp>

/// <summary>
/// An enum class whose values correspond to a screen the user can be on. 
/// </summary>
enum class Gamestate
{
	MainMenu,
	PauseMenu,
	Options,
	Gameplay,
	GameOver,
	Help
};

/// <summary>
/// A #Gamestate variable that keeps track of what screen the user is on.
/// </summary>
extern Gamestate g_gamestate;

/// <summary>
/// A #Gamestate variable that keeps track of what screen the user was previously on.
/// </summary>
extern Gamestate g_previousState;

/// <summary>
/// A bool that stops the game when the player chooses to exit on the Main menu.
/// </summary>
extern bool g_exitGame;

/// <summary>
///  An enum class whose values correspond to the types of Enemy variations there are.
/// </summary>
enum class EnemyType
{
	Bat,
	Rat
};

/// <summary>
/// An enum class whose values correspond to the types of Item variations there are.
/// </summary>
enum class ItemType
{
	Weapon,
	Armour,
	Potion
};

/// <summary>
/// An enum class whose values correspond to the types of Weapon variations there are.
/// </summary>
enum class Weapons
{
	Sword,
	Axe,
	Dagger
};

/// <summary>
/// An enum class whose values correspond to the types of Armour variations there are.
/// </summary>
enum class Armours
{
	Light,
	Medium,
	Heavy
};

/// <summary>
/// An enum class whose values correspond to the types of Potion variations there are.
/// </summary>
enum class Potions
{
	Health,
	Strength,
	Speed
};

/// <summary>
/// An enum class whose values correspond to the types of Scroll variations there are.
/// </summary>
enum class Scrolls
{
	Fireball,
	Shield,
	Teleportation
};

/// <summary>
/// An enum class whose values correspond to the types of Tile variations there are.
/// </summary>
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

/// <summary>
/// The width of the game screen.
/// </summary>
unsigned const int G_VIEW_WIDTH = 1800;

/// <summary>
/// The height of the game screen.
/// </summary>
unsigned const int G_VIEW_HEIGTH = 900;

// Might be used later
//unsigned int Music_volume;
//unsigned int SFX_volume;
//unsigned int SFX_Walking_Volume;

///Maximum number of rows in a Room.
unsigned const int G_ROOM_ROWS = 25; 

///Maximum number of columns in a Room.
unsigned const int G_ROOM_COLS = 20;

///Maximum number of rows on the Grid.
unsigned const int G_MAP_ROWS = 75; 

///Maximum number of columns on the Grid.
unsigned const int G_MAP_COLS = 60; 

///The size of one Tile in the Grid.
unsigned const int G_CELL_SIZE = 32;


//unsigned const int MAP_WIDTH = MAP_ROWS * CELL_SIZE;
//unsigned const int MAP_HEIGTH = MAP_COLS * CELL_SIZE ;


/// <summary>
///The path that leads to a texture that will appear if there was an error loading the first texture.
/// </summary>
std::string const MISSINGTEXTURE = "./ASSETS/IMAGES/MissingTexture.png";

/// <summary>
/// The path that leads to a texture that holds the appearance of the Player, the Enemy, and the Items.
/// </summary>
std::string const ITEMS_TEXTURE = "./ASSETS/IMAGES/tilemap_packed.png";

/// <summary>
///The font used throughout the Game.
/// </summary>
extern sf::Font g_font;

#endif // !GLOBALS_H

