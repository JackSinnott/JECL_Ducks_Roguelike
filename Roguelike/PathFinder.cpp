#include "PathFinder.h"
#include <iostream>

PathFinder* PathFinder::m_instance{ nullptr };

PathFinder::PathFinder() :
	m_graph(G_ROOM_ROWS* G_ROOM_COLS),
	m_links(sf::Lines)
{
	createGraph();
}

//***********************************************

void PathFinder::generatePath(sf::Vector2i t_pathStart, sf::Vector2i t_pathDest, std::stack<sf::Vector2i>& t_path)
{
	if (m_debugInfo)
		resetPath();

	std::stack<Node*> path; // created to invert the path so it goes from start - dest
	std::pair<int, int> indexPos; // first - start, second - end

	//get the index of the start and end points
	indexPos.first = (static_cast<int>(t_pathStart.x) / 32) + ((static_cast<int>(t_pathStart.y) / 32) * 25);
	indexPos.second = (static_cast<int>(t_pathDest.x) / 32) + ((static_cast<int>(t_pathDest.y) / 32) * 25); 

	m_graph.aStar(m_graph.nodeIndex(indexPos.first), m_graph.nodeIndex(indexPos.second), path);

	while (!path.empty())
	{
		pathNode(path.top());
		t_path.push(static_cast<sf::Vector2i>(path.top()->m_data.m_vertex.position));
		path.pop();
	}
	if (m_debugInfo)
		connectLinks();
}

//***********************************************

void PathFinder::pathNode(Node* t_pathNode)
{
	t_pathNode->m_data.m_vertex.color = sf::Color::Blue;
	t_pathNode->m_data.m_debugShow.setFillColor(sf::Color::Blue);
}

//***********************************************

void PathFinder::resetPath()
{
	for (auto& node : m_graph.getNodes())
	{
		node->m_data.m_vertex.color = (node->m_data.m_obstacle) ? sf::Color(255U, 255U, 255U, 50U) : sf::Color::White;
		node->m_data.m_debugShow.setFillColor((node->m_data.m_obstacle) ? sf::Color(255U, 0U, 255U, 50U) : sf::Color(255U, 0U, 255U));
	}
}

//***********************************************

void PathFinder::connectLinks()
{
	m_links.clear();
	for (auto& c : m_graph.getNodes())
		c->setMarked(false);

	std::set<Node*> links;

	for (auto& c : m_graph.getNodes())
		if (!c->m_data.m_obstacle)
			links.insert(c);

	while(links.size())
	{
		auto node = links.begin();
		(*node)->setMarked(true);
		for (auto& arc : (*node)->arcList())
		{
			if (!arc.node()->marked())
			{
				m_links.append((*node)->m_data.m_vertex);
				m_links.append(arc.node()->m_data.m_vertex);
				if (!links.count(arc.node()))
				{
					links.insert(arc.node());
				}
			}
		}
		links.erase(node);
	}
}

//***********************************************

PathFinder& PathFinder::getSingleton()
{
	if (m_instance == nullptr)
	{
		m_instance = new PathFinder();
	}
	return *m_instance;
}

PathFinder::~PathFinder()
{
	delete m_instance;
}

//***********************************************

void PathFinder::linkGraph(std::array<std::array<Tile, G_ROOM_COLS>, G_ROOM_ROWS>& t_data)
{
	int weight = 5;
	int diagWeight = 8;
	int scalar = 25;

	for (int i = 0; i < t_data[0].size(); ++i)
		for (int j = 0; j < t_data.size(); ++j)
			if (t_data[j][i].getType() != TileType::GROUND && t_data[j][i].getType() != TileType::UNUSED && t_data[j][i].getType() != TileType::ENTRANCE)
			{
				m_graph.nodeIndex(i * scalar + j)->m_data.m_obstacle = true;
				m_graph.nodeIndex(i * scalar + j)->m_data.m_vertex.color = sf::Color(255U, 255U, 255U, 50U);
				m_graph.nodeIndex(i * scalar + j)->m_data.m_debugShow.setFillColor(sf::Color(255U, 0U, 255U, 50U));
			}

	// setup obstacles first
	for (int i = 0; i < t_data[0].size(); ++i)
	{ // i = rows
		for (int j = 0; j < t_data.size(); ++j)
		{ // j = cols
			if (m_graph.nodeIndex(i * scalar + j)->m_data.m_obstacle)
				continue;
			if (i != 0) // not the first row, go up 1 row
			{
				if (!m_graph.nodeIndex((i - 1) * scalar + j)->m_data.m_obstacle)
					m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i - 1) * scalar + j), weight);
				if (j != 0) // not the first row or first col, go up and left
					if (!m_graph.nodeIndex((i - 1) * scalar + j)->m_data.m_obstacle && !m_graph.nodeIndex(i * scalar + j - 1)->m_data.m_obstacle)
						m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i - 1) * scalar + j - 1), diagWeight);
				if (j != t_data.size()-1) // not the first row or last col, go up and right
					if (!m_graph.nodeIndex((i - 1) * scalar + j)->m_data.m_obstacle && !m_graph.nodeIndex(i * scalar + j + 1)->m_data.m_obstacle)
						m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i - 1) * scalar + j + 1), diagWeight);
			}
			if (i < t_data[0].size() - 1) // not the last row, go down 1 row
			{
				if (!m_graph.nodeIndex((i + 1) * scalar + j)->m_data.m_obstacle)
					m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i + 1) * scalar + j), weight);
				if (j != 0) // not the last row or first col, go down and left
					if (!m_graph.nodeIndex((i + 1) * scalar  + j)->m_data.m_obstacle && !m_graph.nodeIndex(i * scalar + j - 1)->m_data.m_obstacle)
						m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i + 1) * scalar + j - 1), diagWeight);
				if (j != t_data.size() - 1) // not the last row or last col, go down and right
					if (!m_graph.nodeIndex((i + 1) * scalar + j)->m_data.m_obstacle && !m_graph.nodeIndex(i * scalar + j + 1)->m_data.m_obstacle)
						m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex((i + 1) * scalar + j + 1), diagWeight);
			}
			if (j != 0) // not the first col, go left 1 col
				if (!m_graph.nodeIndex(i * scalar + j - 1)->m_data.m_obstacle)
					m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex(i * scalar + j - 1), weight);
			if (j < t_data.size() - 1) // not the last col, go right 1 col
				if (!m_graph.nodeIndex(i * scalar + j + 1)->m_data.m_obstacle)
					m_graph.nodeIndex(i * scalar + j)->addArc(m_graph.nodeIndex(i * scalar + j + 1), weight);


		}
	}
	connectLinks();
}

//***********************************************

void PathFinder::draw(sf::RenderWindow& t_window)
{
	if (m_debugInfo)
	{
		t_window.draw(m_links);
		for (auto n : m_graph.getNodes())
		{
			t_window.draw(n->m_data.m_debugShow);
		}
	}
}

//***********************************************

void PathFinder::createGraph()
{
	NodeData nodeInfo;
	for (int index = 0; index < m_graph.getSize(); ++index)
	{
		nodeInfo.m_obstacle = false;
		nodeInfo.m_vertex = sf::Vertex{ sf::Vector2f{ (32.0f * (index % 25) + 16.0f),(32.0f * (index / 25) + 16.0f) }, sf::Color::White };
		nodeInfo.m_debugShow.setRadius(5);
		nodeInfo.m_debugShow.setOrigin({ 5.f,5.f });
		nodeInfo.m_debugShow.setFillColor(sf::Color(255U,0U,255U));
		nodeInfo.m_debugShow.setPosition(nodeInfo.m_vertex.position);

		m_graph.addNode(nodeInfo, index);
	}
}
