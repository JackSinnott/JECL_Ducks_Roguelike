#pragma once
#include "Globals.h"

class MainMenu
{
public:
	MainMenu();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
};
