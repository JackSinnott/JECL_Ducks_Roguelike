#ifndef NODE_DATA_INCLUDE
#define NODE_DATA_INCLUDE

#include  <string>
#include <SFML/Graphics.hpp>

// ---------------------------------------------------------------------
//  Name:           NodeData
//  Description:    A simple struct to encapsulate all the node data.
//                  Add or remove fields as required.               
// ---------------------------------------------------------------------
struct NodeData
{
	bool m_obstacle;
	int m_localDistance; // local goal 
	int m_heuristic; // global goal
	sf::Vertex m_vertex;// stores the position and colour of the node

#ifdef DEBUG_INFO
	sf::CircleShape m_debugShow;
#endif // DEBUG_INFO

};

#endif