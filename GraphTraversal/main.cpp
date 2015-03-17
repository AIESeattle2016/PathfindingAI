#include <iostream>

#include "Graph.h"

void main()
{
	Graph levelGraph;

	for (int i = 0; i < 6; i++)
	{
		levelGraph.AddNode(new GraphNode(i));
	}
	
	// Apply the adjacency list
	Edge(levelGraph.GetNode(0), levelGraph.GetNode(1), 0);
	Edge(levelGraph.GetNode(0), levelGraph.GetNode(5), 0);
	Edge(levelGraph.GetNode(1), levelGraph.GetNode(2), 0);
	Edge(levelGraph.GetNode(2), levelGraph.GetNode(0), 0);
	Edge(levelGraph.GetNode(2), levelGraph.GetNode(3), 0);
	Edge(levelGraph.GetNode(3), levelGraph.GetNode(4), 0);
	Edge(levelGraph.GetNode(5), levelGraph.GetNode(3), 0);
	Edge(levelGraph.GetNode(5), levelGraph.GetNode(4), 0);

	levelGraph.PrintGraph();

	// Test Algos
	std::cout << "Can I progress from start to end? " << levelGraph.SearchDFS(levelGraph.GetNode(0), levelGraph.GetNode(4));
	std::cout << "\n";
	levelGraph.ResetVisited();

	std::cin.get();
}