#pragma once
#include "Globals.h"
#include "FileLoader.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"
#include "AbstractItemFactory.h"
#include "WeaponFactory.h"
#include "ArmourFactory.h"
class Gameplay
{
public:
	Gameplay();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
	void GenerateRandomItem(AbstractItemFactory& t_factory);
private:
	void LoadLevel();
	void processTurn();
	void setUpShape();

	sf::Text m_infoText;
	sf::Texture m_tileTexture;
	LevelLoader* m_levelLoader;
	std::shared_ptr<sf::Texture> m_buttonTexture;
	std::vector<sf::Sprite*> m_walls; // a vector to hold the walls
	Grid m_grid;

	//WeaponFactory* exampleWeapon;
	AbstractItemFactory* exampleItem;
	AbstractWeapon* m_absWeapon;

	std::vector<AbstractWeapon*> m_absWeaponVector;
	sf::RectangleShape m_test;

	Player player;
	Enemy* m_testEnemy;
};
