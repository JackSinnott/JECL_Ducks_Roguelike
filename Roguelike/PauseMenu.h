#pragma once
#include "Globals.h"
#include "Button.h"

/// <summary>
/// The PauseMenu screen. Is used to tell the user that the game is paused,
/// and gives them choices on how to proceed.
/// </summary>

class PauseMenu
{
public:
	PauseMenu();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:
	///The Button that will bring you back to the Gameplay.
	Button* m_backButton;

	///The Button that will bring you back to the MainMenu.
	Button* m_menuBackButton;

	///The text that tells you to that the game is paused.
	sf::Text m_gamePauseText;
};
