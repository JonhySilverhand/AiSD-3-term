#include "stdafx.h"

namespace GraphEdgeList
{
	struct Edge
	{
		int begin, end;
		Edge(int begin, int end)
		{
			this->begin = begin;
			this->end = end;
		}
	};

	class Graph
	{
	private:
		vector<list<int>> adjList;
	public:
		Graph(vector<Edge> const& edges, int n);
		void Print();
		void BFS(int s);
	};
}
