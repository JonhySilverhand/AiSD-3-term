#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

typedef struct items
{
    char name[20];
    unsigned int weight;
    float profit;
};

float max(float a, float b)
{
    return ((a > b) ? a : b);
}

float knapsack(unsigned int n, struct items object[], unsigned int capacity)
{
    float** table = new float* [n + 1];

    for (unsigned int i = 0; i <= n; i++)
    {
        table[i] = new float[capacity + 1];
        for (unsigned int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0.0;
            else if (object[i - 1].weight <= j)
                table[i][j] = max((object[i - 1].profit + table[i - 1][j - object[i - 1].weight]), table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    //Printing table
    //printf("Printing profit table\n");
    //for (unsigned int i = 0; i <= n; i++)
    //{
    //    for (unsigned int j = 0; j <= capacity; j++)
    //        printf("%.1f\t", table[i][j]);
    //    printf("\n");
    //}
    return table[n][capacity];
}

void main()
{
    setlocale(LC_ALL, "rus");

    unsigned int capacity;
    cout << "����� �������:";
    cin >> capacity;

    unsigned int n;
    cout << "����� ���-�� ���������: ";
    cin >> n;

    items* item = new items[n];

    cout<< "������� ������������� ������:\n";
    for (unsigned int i = 0; i < n; i++)
    {
        cout << "-------- ���� � " << i + 1 << "--------\n";
        cout << "��� : ";
        cin >> item[i].name;
        cout << "��� : ";
        cin >> item[i].weight;
        cout << "����: ";
        cin >> item[i].profit;
    }

    float max_profit = knapsack(n, item, capacity);

    cout << "������������ �������:\n" <<  max_profit;
}