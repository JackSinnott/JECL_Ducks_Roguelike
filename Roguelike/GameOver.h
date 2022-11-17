#pragma once
#include "Globals.h"

class GameOver
{
public:
	GameOver();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
};
