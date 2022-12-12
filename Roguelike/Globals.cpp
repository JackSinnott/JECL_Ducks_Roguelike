#include "Globals.h"

Gamestate g_gamestate = Gamestate::MainMenu;
Gamestate g_previousState = Gamestate::MainMenu;
bool g_exitGame = false;

sf::Font g_font;