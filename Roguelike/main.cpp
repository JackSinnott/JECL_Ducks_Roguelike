#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "Game.h"

/// <summary>
/// Sets up the font that is used in the game.
/// </summary>
void setupFont()
{
	if (!g_font.loadFromFile("./ASSETS/FONTS/ariblk.ttf"))
	{
		std::cout << "font not loading" << std::endl;
	}
}

/// <summary>
/// The starting function.
/// </summary>
/// <returns>success or failure of the entire program.</returns>
int main()
{
	setupFont();
	Game game;
	game.run();

	return 1; // success
}