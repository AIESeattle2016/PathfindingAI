#include "Graph.h"

#include <iostream>
#include <stack>
#include <cassert>

// # Graph
void Graph::AddNode(GraphNode * a_pNode)
{
	for (auto node : m_aNodes)
	{
		assert(a_pNode->m_iNodeNumber != node->m_iNodeNumber, "ID of new node must be unique");
	}

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
GraphNode* Graph::GetNode(int a_nodeID)
{
	for (auto node : m_aNodes)
	{
		if (node->m_iNodeNumber == a_nodeID)
		{
			return node;
		}
	}
}
void Graph::PrintGraph()
{
	std::cout << "--GRAPH DEBUGGING--" << "\n";

	for (auto node : m_aNodes)
	{
		node->PrintNeighbors();
	}
}

// # GraphNode
GraphNode::GraphNode(int a_iNum) : m_iNodeNumber(a_iNum)
{

}
void GraphNode::AddEdge(const Edge& edge)
{
	m_aEdges.emplace_back(edge);
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
void Graph::ResetVisited()
{
	for (auto node : m_aNodes)
	{
		node->m_wasVisited = false;
	}
}
bool Graph::SearchDFS(GraphNode * a_pStart, GraphNode * a_pEnd)
{
	std::stack<GraphNode*> oNodeStack;
	oNodeStack.push(a_pStart);

	//keep looping until the stack is empty. 
	//This will only happen once we've checked every node. 
	while (!oNodeStack.empty())
	{
		//Add to while loop
		GraphNode* pCurrent = oNodeStack.top();
		oNodeStack.pop();

		//Add to while loop

		if (pCurrent->m_wasVisited == true)
		{
			continue;
		}

		pCurrent->m_wasVisited = true;

		//Add to while loop
		if (pCurrent == a_pEnd)
		{
			return true;
		}

		//Add to while loop
		for (int i = 0; i < pCurrent->m_aEdges.size(); ++i)
		{
			oNodeStack.push(pCurrent->m_aEdges[i].m_pEnd);
		}
	}

	//return false if we didn't find a_pEnd
	return false;
}

// # Edge
Edge::Edge(GraphNode * a_pStart, GraphNode * a_pEnd, float a_fCost=0)
: m_pStart(a_pStart), m_pEnd(a_pEnd), m_fCost(a_fCost)
{
	m_pStart->AddEdge(*this);
	//m_pEnd->AddEdge(*this);
}                                                                                                                                                                                                                                   