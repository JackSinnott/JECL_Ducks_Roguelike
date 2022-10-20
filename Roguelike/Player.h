#pragma once
#include "SFML/Graphics.hpp"


/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:

	// Variables

	//sf::Sprite m_playerBody; 

	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::RectangleShape m_playerBody;

	/// Reference to the texture of the player.
	sf::Texture* m_playerTexture;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button.
	/// </summary>
	sf::Keyboard::Key m_pressingButton = sf::Keyboard::Unknown;

	/// <summary>
	/// Temporary variable - Used for moving between grid cells.
	/// Will be replaced once Grid class is set up.
	/// </summary>
	float gridCellSize = 50.0f;


	// Methods / Functions

	void MoveSquare(sf::Vector2f t_direction);

public:

	//void InitialiseTextures();

	Player();

	void Update(sf::Time t_deltaTime);
	bool ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);

	sf::Vector2f GetPosition();
};