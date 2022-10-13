/// <summary>
/// Author: Jack Sinnott
/// Tilemap: Used to seperate the game world into grids that we then apply textures to to create the map.
/// Inheritance: 
/// - sf::Drawable: Useful as it allows us to draw a container of objects with very little extra work necessary
/// - sf::Transformable: Useful as it allows us to use SFML Transformation function calls on the objects created
/// </summary>

#ifndef TILEMAP
#define TILEMAP

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	// Fetch the image asset and get it dimensions then divide the dimensions by the number of tiles
	bool load(const std::string& t_tileset, sf::Vector2u tileSize, const int* t_tiles,
		unsigned int t_width, unsigned int t_height);

private:
	// Inherited from sf::Drawable
	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	sf::VertexArray m_vertices; // Vertexs that encapsulate the image being currently drawn
	sf::Texture m_tileSet; // Texture we are using for the tiles
};

#endif // !TILEMAP