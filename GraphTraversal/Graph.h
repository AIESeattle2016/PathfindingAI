#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Edge;

class GraphNode
{
public:
	GraphNode(int a_iNum);

	typedef std::vector<Edge> EdgeList;
	EdgeList m_aEdges;

	void AddEdge(const Edge& edge);
	void PrintNeighbors();

	

	int m_iNodeNumber;
};

class Graph
{
	typedef std::vector<GraphNode*> NodeList;
public:
	Graph() {}

	void AddNode(GraphNode * a_pNode);
	bool RemoveNode(const GraphNode * a_pNode);

	void PrintGraph();

private:
	NodeList m_aNodes;
};

struct Edge
{
	Edge() {}
	Edge(GraphNode * a_pStart, GraphNode * a_pEnd, float a_fCost);

	GraphNode * m_pStart;
	GraphNode * m_pEnd;

	float m_fCost;
};

#endif