#include "stdafx.h"
#include "GraphEdgeList.h"

namespace GraphEdgeList
{
	Graph::Graph(vector<Edge> const& edges, int n)
	{
		adjList.resize(n);

		for (auto& edge : edges)
		{
			adjList[edge.begin - 1].push_back(edge.end);
			adjList[edge.end - 1].push_back(edge.begin);
		}
	}
	void Graph::Print()
	{
		for (int i = 0; i < 10; i++)
		{
			for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it)
			{
				cout << i + 1 << " - " << *it << endl;
			}
		}
	}
	void Graph::BFS(int v)
	{
		vector<bool> visit(10, false);
		queue<int> q;
		visit[v - 1] = true;
		q.push(v);

		while (!q.empty())
		{
			v = q.front();
			q.pop();
			cout << v << " ";
			for (int u : adjList[v - 1])
			{
				if (!visit[u - 1])
				{
					visit[u - 1] = true;
					q.push(u);
				}
			}
		}
	}
}