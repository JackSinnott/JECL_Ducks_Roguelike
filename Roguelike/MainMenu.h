#pragma once
#include "Globals.h"
#include "Button.h"

/// <summary>
/// The main screen the user will see once they open the game.
/// </summary>

class MainMenu
{
public:
	MainMenu();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:

	/// All the Button objects that appear on the MainMenu.
	std::vector<Button*> m_buttons;
};
