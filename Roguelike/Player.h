#pragma once
#include "SFML/Graphics.hpp"


/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:

	sf::Sprite m_playerBody; // Appearance of player.
	sf::Texture* m_playerSprite; // Reference to the texture of the player.



public:

	void Update(sf::Time t_deltaTime);
	void ProcessKeys(sf::Event t_event);
};

