#pragma once
#include "Globals.h"

class Button
{
public:
	Button(sf::Vector2f t_pos, sf::Vector2f t_size, std::string t_buttonText, sf::Color t_idle, sf::Color t_hover, sf::Color t_click);
	void onMouseDown();
	bool onMouseUp();
	void update(sf::Vector2i t_pos);
	void render(sf::RenderWindow& t_window);
private:
	sf::RectangleShape button;
	sf::Text buttonText;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color clickColor;
	bool hover = false;
	bool clicking = false;

	void changeColor();
};
