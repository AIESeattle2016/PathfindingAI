#include "Graph.h"

#include <iostream>

void GraphNode::AddEdge(const Edge& edge)
{
	m_aEdges.emplace_back(edge);
}

void Graph::AddNode(GraphNode * a_pNode)
{
	m_aNodes.emplace_back(a_pNode);
}

bool Graph::RemoveNode(const GraphNode * a_pNode)
{
	// loop over each node and delete any related edges
	for (auto nodeIt = m_aNodes.begin();
		nodeIt != m_aNodes.end();
		++nodeIt)
	{
		for (auto edgeIt = (*nodeIt)->m_aEdges.begin();
			edgeIt != (*nodeIt)->m_aEdges.end();
			++edgeIt)
		{
			if (edgeIt->m_pEnd == a_pNode)
			{
				edgeIt = (*nodeIt)->m_aEdges.erase(edgeIt);
			}
		}
	}

	// find the node and delete it
	for (auto listIt = m_aNodes.begin();
		listIt != m_aNodes.end();
		++listIt)
	{
		if (*listIt == a_pNode)
		{
			m_aNodes.erase(listIt);
			return true;
		}
	}

	return false;
}

void Graph::PrintGraph()
{
	std::cout << "--GRAPH DEBUGGING--" << "\n";

	for (auto node : m_aNodes)
	{
		node->PrintNeighbors();
	}
}

GraphNode::GraphNode(int a_iNum) : m_iNodeNumber(a_iNum)
{

}

void GraphNode::PrintNeighbors()
{
	std::cout << "Node #" << m_iNodeNumber << "" << "\n";

	for (auto edge : m_aEdges)
	{
		std::cout << "  * " << edge.m_pEnd->m_iNodeNumber << "\n";
	}

	std::cout << "\n";
}

Edge::Edge(GraphNode * a_pStart, GraphNode * a_pEnd, float a_fCost=0)
: m_pStart(a_pStart), m_pEnd(a_pEnd), m_fCost(a_fCost)
{
	m_pStart->AddEdge(*this);
	//m_pEnd->AddEdge(*this);
}