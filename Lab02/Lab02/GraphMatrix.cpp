#include "stdafx.h"
#include "GraphMatrix.h"

namespace GraphMatrix
{
	void Graph::Print()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << Gmatrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void Graph::BFS(int num)
	{
		queue<int> Q;
		vector<bool> visit(10, false);
		Q.push(num);
		visit[num - 1] = true;
		int vis;
		while (!Q.empty())
		{
			vis = Q.front();
			cout << vis << " ";
			Q.pop();
			for (int i = 0; i < 10; i++)
			{
				if (Gmatrix[vis - 1][i] == 1 && (!visit[i]))
				{
					Q.push(i + 1);
					visit[i] = true;
				}
			}
		}
	}
	void Graph::DFS(int num)
	{
		stack<int> S;
		vector<bool> visit(10, false);
		S.push(num);
		visit[num - 1] = true;
		int vis;
		while (!S.empty())
		{
			vis = S.top();
			cout << vis << " ";
			S.pop();
			for (int i = 9; i >= 0; i--)
			{
				if (Gmatrix[vis - 1][i] == 1 && (!visit[i]))
				{
					S.push(i + 1);
					visit[i] = true;
				}
			}
		}
	}
}
