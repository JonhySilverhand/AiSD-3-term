#include "stdafx.h"
#include "Graph.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "������ ����� ��������� ������ � �� ��� (�������� �����)" << endl;
    graph.Prims();
    cout << "\n������ ����� ��������� ������ � �� ��� (�������� ��������)" << endl;
    graph.Kruskals();
}
