#pragma once
#include "Globals.h"
#include "Button.h"

/// <summary>
/// The Options screen. Is used to let the user adjust their experience of the game.
/// </summary>

class Options
{
public:
	Options();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:

	/// The Button that will bring you back to the MainMenu.
	Button* m_backButton;
};
