#include "Help.h"

/// <summary>
/// The default constructor.
/// </summary>
Help::Help()
{
	sf::Vector2f buttonSize = sf::Vector2f(250, 100);
	m_backButton = new Button(sf::Vector2f(G_VIEW_WIDTH - (buttonSize.x + 20), G_VIEW_HEIGTH - (buttonSize.y + 20)),
		buttonSize, "BACK", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	const int line_no = 3;
	std::string help[line_no] = {
		"Move using the arrow keys", 
		"Find the stairs to the next floor", 
		"Avoid enemies" 
	};

	for (int i = 0; i < line_no; i++)
	{
		sf::Text newLine;
		newLine.setFont(g_font);
		newLine.setString(help[i]);
		newLine.setCharacterSize(40);
		newLine.setFillColor(sf::Color::White);
		newLine.setPosition(G_VIEW_WIDTH / 2, G_VIEW_HEIGTH / 4 + (50 * i));
		newLine.setOrigin(newLine.getLocalBounds().width / 2.0f, newLine.getLocalBounds().height / 2.0f);
		helpText.push_back(newLine);
	}
	
}

/// <summary>
/// Handles any events the player has triggered while on the Help Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void Help::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			m_backButton->onMouseDown();
		}
	}
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			if (m_backButton->onMouseUp())
			{
				g_gamestate = Gamestate::MainMenu;
			}
		}
	}
}

/// <summary>
/// Updates the back Button.
/// </summary>
/// <param name="t_mousePos">The mouse's position on the screen.</param>
void Help::update(sf::Vector2i t_mousePos)
{
	m_backButton->update(t_mousePos);
}

/// <summary>
/// Draws all what's happening on the help screen.
/// </summary>
/// <param name="t_window">The screen to draw to.</param>
void Help::render(sf::RenderWindow& t_window)
{
	for (sf::Text line : helpText)
	{
		t_window.draw(line);
	}

	m_backButton->render(t_window);
	t_window.setView(t_window.getDefaultView());
}
