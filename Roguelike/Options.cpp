#include "Options.h"

Options::Options()
{
	sf::Vector2f buttonWidth = sf::Vector2f(250, 100);
	m_backButton = new Button(sf::Vector2f(G_VIEW_WIDTH - (buttonWidth.x + 20), G_VIEW_HEIGTH - (buttonWidth.y + 20)),
		buttonWidth, "BACK", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);
}

void Options::processEvents(sf::Event t_event)
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
				m_gamestate = Gamestate::MainMenu;
			}
		}
	}
}

void Options::update(sf::Vector2i t_mousePos)
{
	m_backButton->update(t_mousePos);
}

void Options::render(sf::RenderWindow& t_window)
{
	m_backButton->render(t_window);
}
