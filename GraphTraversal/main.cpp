#include <iostream>

#include "Graph.h"

void main()
{
	Graph levelGraph;

	GraphNode * a0 = new GraphNode(0);
	GraphNode * a1 = new GraphNode(1);

	Edge a0_a1;
	a0_a1.m_pStart = a0;
	a0_a1.m_pEnd = a1;
	a0_a1.m_fCost = 1;
	a0->AddEdge(a0_a1);

	Edge a1_a0(a1,a0, 0);

	//a0->PrintNeighbors();
	//a1->PrintNeighbors();

	levelGraph.AddNode(a0);
	levelGraph.AddNode(a1);

	levelGraph.PrintGraph();

	std::cin.get();
}