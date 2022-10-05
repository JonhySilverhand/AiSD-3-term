#include "stdafx.h"
#include "Graph.h"

void Graph::Print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << graphM[i][j] << "\t";
		}
		cout << endl;
	}
}
int Graph::minDist(int dist[], bool visit[])
{
	int min = INT_MAX, minIndex;
	for (int i = 0; i < 9; i++)
	{
		if (visit[i] == false && dist[i] <= min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void Graph::printSolution(int dist[])
{
	for (int i = 0; i < 9; i++)
	{
		cout << this->vertices[i] << " -- " << dist[i] << endl;
	}
}
void Graph::dijkstra(char c)
{
	auto itr = find(vertices, vertices + 8, c);
	int src = distance(vertices, itr);
	int dist[9];
	bool visit[9];
	for (int i = 0; i < 9; i++)
	{
		dist[i] = INT_MAX;
		visit[i] = false;
	}
	dist[src] = 0;
	for (int k = 0; k < 8; k++)
	{
		int u = this->minDist(dist, visit);
		visit[u] = true;
		for (int j = 0; j < 9; j++)
		{
			if (!visit[j] && this->graphM[u][j] && dist[u] != INT_MAX
				&& dist[u] + this->graphM[u][j] < dist[j])
				dist[j] = dist[u] + this->graphM[u][j];
		}
	}
	this->printSolution(dist);
}