#pragma once
#include "Globals.h"
#include "Options.h"

/// <summary>
/// The GameOver screen. It is accessed after the Player's health is 0 during Gameplay.
/// </summary>

class GameOver
{
public:
	GameOver();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:

	/// The Button that will bring you back to the MainMenu.
	Button* m_backButton;

	/// The text that will tell the player that they died.
	sf::Text m_loseText;
};
