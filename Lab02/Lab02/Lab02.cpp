#include <iostream>
#include "stdafx.h"
#include "GraphAdjacencyList.h"
#include "GraphEdgeList.h"
#include "GraphMatrix.h"

namespace GEL = GraphEdgeList;
namespace GM = GraphMatrix;
namespace GAL = GraphAdjacencyList;

int main()
{
	setlocale(LC_ALL, "Ru");
	GM::Graph graphsec;

	cout << "Поиск в ширину: " << endl;
	graphsec.BFS(1);
	cout << endl;
	cout << "Поиск в глубину: " << endl;
	graphsec.DFS(1);

	cout << "\n\n\nСписок ребер графа: " << endl;
	vector<GEL::Edge> edges = {
		{1, 2}, {1, 5}, {5, 6}, {2, 7}, {2, 8}, {7, 8}, {3, 8}, {4, 6}, {4, 9}, {9, 10}
	};
	GEL::Graph graphfirst(edges, 10);
	graphfirst.Print();

	cout << "\nМатрица смежности для графа: " << endl;
	graphsec.Print();

	cout << "\n\nСписок смежности для графа: " << endl;
	GAL::Graph graphthird(10);

	graphthird.addEdge(1, 2);
	graphthird.addEdge(1, 5);
	graphthird.addEdge(2, 1);
	graphthird.addEdge(2, 7);
	graphthird.addEdge(2, 8);
	graphthird.addEdge(3, 8);
	graphthird.addEdge(4, 6);
	graphthird.addEdge(4, 9);
	graphthird.addEdge(5, 1);
	graphthird.addEdge(5, 6);
	graphthird.addEdge(6, 4);
	graphthird.addEdge(6, 5);
	graphthird.addEdge(6, 9);
	graphthird.addEdge(7, 2);
	graphthird.addEdge(7, 8);
	graphthird.addEdge(8, 2);
	graphthird.addEdge(8, 3);
	graphthird.addEdge(8, 7);
	graphthird.addEdge(9, 4);
	graphthird.addEdge(9, 6);
	graphthird.addEdge(9, 10);
	graphthird.addEdge(10, 9);
	graphthird.Print();
	cout << endl;
	system("pause");
	return 0;
}