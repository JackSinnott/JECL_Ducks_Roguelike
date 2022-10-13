#include "Tilemap.h"

// Find the image and set up its dimensions and grid
bool Tilemap::load(const std::string& t_tileset, sf::Vector2u t_tileSize, const int* t_tiles, unsigned int t_width, unsigned int t_height)
{
    if (!m_tileSet.loadFromFile("ASSETS\\IMAGES\\BasicTilemap.png"))
        return false;

    m_vertices.setPrimitiveType(sf::Quads); // We need a square to encapsulate the sprite we want to use
    m_vertices.resize(t_width * t_height * 4); // The image is a certain size 


    for (unsigned int i = 0; i < t_width; ++i)
        for (unsigned int j = 0; j < t_height; ++j)
        {
            // What tile are we currently interested in
            int m_tileNumber = t_tiles[i + j * t_width];

            // Find where that tile is in our image
            int m_tu = m_tileNumber % (m_tileSet.getSize().x / t_tileSize.x);
            int m_tv = m_tileNumber / (m_tileSet.getSize().x / t_tileSize.x);

            // Point to the current tiles vertex quad
            sf::Vertex* m_quad = &m_vertices[(i + j * t_width) * 4];

            // Assign the quad its corner positions
            m_quad[0].position = sf::Vector2f(i * t_tileSize.x, j * t_tileSize.y);
            m_quad[1].position = sf::Vector2f((i + 1) * t_tileSize.x, j * t_tileSize.y);
            m_quad[2].position = sf::Vector2f((i + 1) * t_tileSize.x, (j + 1) * t_tileSize.y);
            m_quad[3].position = sf::Vector2f(i * t_tileSize.x, (j + 1) * t_tileSize.y);

            // Assign the quad its texture co-ordinates
            m_quad[0].texCoords = sf::Vector2f(m_tu * t_tileSize.x, m_tv * t_tileSize.y);
            m_quad[1].texCoords = sf::Vector2f((m_tu + 1) * t_tileSize.x, m_tv * t_tileSize.y);
            m_quad[2].texCoords = sf::Vector2f((m_tu + 1) * t_tileSize.x, (m_tv + 1) * t_tileSize.y);
            m_quad[3].texCoords = sf::Vector2f(m_tu * t_tileSize.x, (m_tv + 1) * t_tileSize.y);
        }

    return true;


}

// Draw our tile 
void Tilemap::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
    // Apply transform
    t_states.transform *= getTransform();

    // Apply texture
    t_states.texture = &m_tileSet;

    // Draw vertex array
    t_target.draw(m_vertices, t_states);
}
