#pragma once
#include "Globals.h"

class Options
{
public:
	Options();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
};
