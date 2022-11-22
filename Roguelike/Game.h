
/// <summary>
///	Authors:
/// Jack
/// Eoin
/// Caroline
///	Leo
/// Start Date: 13/10/2022
///
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
#include "AbstractItemFactory.h"
#include "WeaponFactory.h"
#include "ArmourFactory.h"
#include "GameData.h"
#include "Globals.h"
#include "FileLoader.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"
#include <time.h>
//#include <vector>
<<<<<<< HEAD

#include "Globals.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "Options.h"
=======
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11

/// <summary>
/// Game Class. Keeps track of Game Flow.
/// </summary>

class Game
{
public:
	//Game(sf::Font& t_font);
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);

	void Update(sf::Time t_dt);

	void Render(sf::RenderWindow& t_window);
	Gameplay m_gameScreen;
	MainMenu m_mainMenuScreen;
	PauseMenu m_pauseScreen;
	GameOver m_gameOverScreen;
	Options m_optionScreen;

	void GenerateRandomItem(AbstractItemFactory& t_factory);

	//WeaponFactory* exampleWeapon;
	AbstractItemFactory* exampleItem;
	AbstractWeapon* m_absWeapon;

	std::vector<AbstractWeapon*> m_absWeaponVector;

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

<<<<<<< HEAD
=======
	Player player;
	//Weapon m_genericWeapon;
	//Weapon* m_testWeapon;
	Enemy* m_testEnemy;
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11
};

#endif // !GAME_HPP

