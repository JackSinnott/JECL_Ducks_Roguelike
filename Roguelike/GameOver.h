#pragma once
#include "Globals.h"
#include "Options.h"

class GameOver
{
public:
	GameOver();
	void processEvents(sf::Event t_event);
	void update(sf::Vector2i t_mousePos);
	void render(sf::RenderWindow& t_window);
private:
	Button* m_backButton;
	sf::Text m_loseText;
};
