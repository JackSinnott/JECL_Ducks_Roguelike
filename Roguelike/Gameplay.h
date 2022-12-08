#pragma once
#include "Globals.h"
#include "FileLoader.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"
#include "AbstractItemFactory.h"
#include "WeaponFactory.h"
#include "ArmourFactory.h"
#include "PotionFactory.h"
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
	//void setUpShape();
	sf::Font m_arialBlackfont; // font used by message
	sf::Text m_mouseCoordinate; // text used for message on screen
	sf::Vector2f m_mousePositionView;

	sf::Text m_infoText;
	sf::Texture m_tileTexture;
	LevelLoader* m_levelLoader;
	std::shared_ptr<sf::Texture> m_buttonTexture;
	std::vector<sf::Sprite*> m_walls; // a vector to hold the walls
	Grid m_grid;

	AbstractItemFactory* m_itemfactory; // Uses a factory method that allows the generation of items
	AbstractItem* m_absItem; // The item itself that can be used to assigned the generated item

	std::vector<AbstractItem*> m_absItemVector; // A vector of items used to store what item is created

	Player player;
	Enemy* m_testEnemy;

	bool m_debugTools;
};
