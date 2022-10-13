#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Tilemap.h"

/// <summary>
/// Game Class. Keeps track of Game Flow.
/// </summary>

class Game
{
public:

	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	void setupSprite();
	void CreateMap();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

	Tilemap m_map; // Create an instance of our Tilemap class
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

