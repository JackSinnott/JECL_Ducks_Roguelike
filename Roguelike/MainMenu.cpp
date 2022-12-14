#include "MainMenu.h"

/// <summary>
/// The Default constructor.
/// </summary>
MainMenu::MainMenu()
{
	sf::Vector2f buttonSize = sf::Vector2f(400, 150);
	std::string buttonTexts[4] = { "PLAY", "HELP", "OPTIONS", "EXIT" };
	for (int i = 0; i < 4; i++)
	{
		m_buttons.push_back(new Button(sf::Vector2f(G_VIEW_WIDTH * 0.5f - (buttonSize.x / 2), G_VIEW_HEIGTH / 8 + (buttonSize.y * 1.2 * i)),
		buttonSize, buttonTexts[i], sf::Color::Yellow, sf::Color::Red, sf::Color::Green));
	}
	
}

/// <summary>
/// Handles any events the player has triggered while on the MainMenu Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void MainMenu::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			for (Button* button : m_buttons)
			{
				button->onMouseDown();
			}
		}
	}
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			int counter = 0;
			for (Button* button : m_buttons)
			{
				if (button->onMouseUp())
				{
					switch (counter)
					{
					case 0:
						g_gamestate = Gamestate::Gameplay;
						break;
					case 1:
						g_gamestate = Gamestate::Help;
						break;
					case 2:
						g_gamestate = Gamestate::Options;
						break;
					case 3:
						g_exitGame = true;
						break;
					}
				}
				counter++;
			}
		}
	}
}

/// <summary>
/// Updates the Button objects on the screen.
/// </summary>
/// <param name="t_mousePos">The mouse's position on the screen.</param>
void MainMenu::update(sf::Vector2i t_mousePos)
{
	for (Button* button : m_buttons)
	{
		button->update(t_mousePos);
	}
}

/// <summary>
/// Draws all what's happening on the menu screen.
/// </summary>
/// <param name="t_window">The screen to draw to.</param>
void MainMenu::render(sf::RenderWindow& t_window)
{
	for (Button* button : m_buttons)
	{
		button->render(t_window);
	}

	t_window.setView(t_window.getDefaultView());
}
