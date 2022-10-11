#include "stdafx.h"

void Graph::FloydWorshell()
{
	for (int m = 0; m < 6; m++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (D[i][m] + D[m][j] < D[i][j])
				{
					D[i][j] = D[i][m] + D[m][j];
					S[i][j] = S[i][m];
				}
			}
		}
	}
}
void Graph::Print()
{
	cout << "Матрица D: " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << D[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	cout << "Матрица S: " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << S[i][j] << '\t';
		}
		cout << endl;
	}
}