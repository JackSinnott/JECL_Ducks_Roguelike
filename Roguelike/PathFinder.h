#ifndef PATH_FINDER_INCLUDE
#define PATH_FINDER_INCLUDE


#define DEBUG_INFO = true;

#include "Comparer.h"
#include "Graph.h"
#include "NodeData.h"
#include <set>
#include "Grid.h"
#include "Tile.h"

typedef GraphNode<NodeData, int> Node;

class PathFinder
{
public:
	PathFinder& getSingleton();
	~PathFinder();
	
	/// <summary>
	/// use the nearest neighbour algorithm to link all the nodes together
	/// </summary>
	/// <param name="m_levelArray"> level data to read where the blockages are </param>
	/// <param name="size"> size of the above array</param>
	void linkGraph(std::array<std::array<Tile,60>,75>& t_data);

	//test
	void draw(sf::RenderWindow& t_window);

	/// <summary>
	/// @Brief Function called from other classes to invoke A* inside the graph
	/// </summary>
	/// <param name="t_pathStart"> where you you want the path to start </param>
	/// <param name="t_pathDest"> where the path will end </param>
	/// <param name="t_path"> Where the path will be stored </param>
	void generatePath(sf::Vector2i t_pathStart, sf::Vector2i t_pathDest, std::stack<sf::Vector2i>& t_path);

	/// <summary>
	/// @Brief Function toggles wether or not the debug info is being drawn on the screen or not
	/// </summary>
	inline void toggleDebug() { m_debugInfo = !m_debugInfo; }

	inline bool getDebug() { return m_debugInfo; }

private:

	void pathNode(Node* t_pathNode);

	void resetPath();

	PathFinder();

	/// <summary>
	/// @brief adds all the arcs to a vertex array to be drawn at a later stage
	/// </summary>
	void connectLinks();

	/// <summary>
	/// Create all the nodes and add all the information to the graph
	/// </summary>
	void createGraph();

	static PathFinder* m_instance; // only allows one instance of the Pathfinder to exits

	Graph<NodeData, int> m_graph; // used to store all the information for the nodes

	sf::VertexArray m_links; // used to draw the connections between the nodes

	bool m_debugInfo; // controls wether the debug information is shown or not
};
#endif