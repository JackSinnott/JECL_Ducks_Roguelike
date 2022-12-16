#pragma once
#include "Globals.h"
#include "FileLoader.h"
#include "Player.h"
#include "Bat.h"
#include "Rat.h"
#include "Grid.h"
#include "AbstractItemFactory.h"
#include "WeaponFactory.h"
#include "ArmourFactory.h"
#include "PotionFactory.h"

/// <summary>
/// The Gameplay screen. This is where the Grid, Player and Enemy objects are handled.
/// </summary>

class Gameplay
{
public:

	Gameplay();
	void processEvents(sf::Event t_event);
	void update(sf::Time t_dt);
	void render(sf::RenderWindow& t_window);
	void GenerateRandomItem();
	void MouseEvents(sf::Event t_event);

	void ResetGame();
private:
	void LoadLevel();
	void processTurn();
	
	///The font used by the Text objects.
	sf::Font m_arialBlackfont; 

	///The text used for messages on the screen.
	sf::Text m_mouseCoordinate; 

	///The position of the mouse on the screen.
	sf::Vector2f m_mousePositionView;

	///Extra text. 
	sf::Text m_infoText;

	///How all the Grid Tiles took like. They will be cropped depending on their #TileType.
	sf::Texture m_tileTexture;

	///Instance of a class that can load Room objects from text files.
	LevelLoader* m_levelLoader;

	///The texture of the buttons on screen.
	std::shared_ptr<sf::Texture> m_buttonTexture;

	///a vector to hold the walls around the Grid.
	std::vector<sf::Sprite*> m_walls;

	/// The area that the Player and Enemy will be moving about. Split into Tiles.
	Grid m_grid;

	///Uses a factory method that allows the generation of items
	AbstractItemFactory* m_itemfactory;

	///The item itself that can be used to assigned the generated item
	AbstractItem* m_absItem;

	///A vector of items used to store what item is created.
	std::vector<AbstractItem*> m_absItemVector; 

	/// the player, that the user will control.
	Player player;

	/// a vetor to store all enemies regardless of type
	std::vector<Enemy*> m_enemies;

	///Controls whether the mouse coordinates are displayed on screen. Used for debugging.
	bool m_debugTools;
};
