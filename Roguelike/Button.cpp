#include "Button.h"

Button::Button(sf::Vector2f t_pos, sf::Vector2f t_size, std::string t_buttonText, sf::Color t_idle, sf::Color t_hover, sf::Color t_click) :
	idleColor(t_idle), hoverColor(t_hover), clickColor(t_click)
{
	button.setPosition(t_pos);
	button.setSize(t_size);
	button.setFillColor(idleColor);
	button.setOutlineThickness(5);

	buttonText.setFont(g_font);
	buttonText.setString(t_buttonText);
	buttonText.setCharacterSize(40);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setPosition(t_pos.x + (t_size.x / 2.0f), t_pos.y + (t_size.y / 2.0f));
	buttonText.setOrigin(buttonText.getLocalBounds().width / 2.0f, buttonText.getLocalBounds().height / 2.0f);
}

void Button::onMouseDown()
{
	if (hover)
	{
		clicking = true;
	}
}

bool Button::onMouseUp()
{
	clicking = false;
	return hover;
}

void Button::update(sf::Vector2i t_pos)
{
	sf::Vector2f pos = button.getPosition();
	sf::Vector2f size = button.getSize();
	if (t_pos.x > pos.x && t_pos.x < pos.x + size.x &&
		t_pos.y > pos.y && t_pos.y < pos.y + size.y)
	{
		hover = true;
	}
	else
	{
		hover = false;
	}
	changeColor();
}

void Button::render(sf::RenderWindow& t_window)
{
	t_window.draw(button);
	t_window.draw(buttonText);
}

void Button::changeColor()
{
	if (clicking)
	{
		button.setFillColor(clickColor);
	}
	else if (hover)
	{
		button.setFillColor(hoverColor);
	}
	else
	{
		button.setFillColor(idleColor);
	}
}
