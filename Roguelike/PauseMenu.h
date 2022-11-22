#pragma once
#include "Globals.h"

class PauseMenu
{
public:
	PauseMenu();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
};
