#pragma once
#include "SFML/Graphics.hpp"


/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:

	//sf::Sprite m_playerBody;

	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::RectangleShape m_playerBody;

	/// Reference to the texture of the player.
	sf::Texture* m_playerTexture;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button
	/// </summary>
	bool pressingButton = false;

public:

	//void InitialiseTextures();

	Player();

	void Update(sf::Time t_deltaTime);
	void ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);
};

