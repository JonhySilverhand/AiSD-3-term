#include <iostream>
#include "Graph.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Graph graph;
	graph.dijkstra('B');
	system("pause");
	return 0;
}