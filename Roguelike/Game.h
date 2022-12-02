
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

#include <time.h>
#include "Globals.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "Options.h"
#include "Help.h"

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
	Help m_helpScreen;

	//WeaponFactory* exampleWeapon;
	AbstractItemFactory* m_itemfactory;
	AbstractWeapon* m_absWeapon;

	std::vector<AbstractWeapon*> m_absWeaponVector;

	sf::RenderWindow m_window; // main SFML window
};

#endif // !GAME_HPP

