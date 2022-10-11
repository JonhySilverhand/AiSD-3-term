#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	Graph graph;
	graph.FloydWorshell();
	graph.Print();
	return 0;
}