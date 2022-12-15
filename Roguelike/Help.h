#pragma once
#include "Globals.h"
#include "Button.h"

/// <summary>
/// The Help screen. Is used to tell the user how to play the game.
/// </summary>

class Help
{
public:
	Help();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:

	///The Button that will bring you back to the MainMenu.
	Button* m_backButton;

	/// The text that will tell the player how to play.
	std::vector<sf::Text> helpText;
};
