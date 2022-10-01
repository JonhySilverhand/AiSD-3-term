#include <iostream>

using namespace std;

void hanoi(int n, int i, int k)
{
	if (n == 1)
		cout << "����������� ���� 1 � " << i << " �� " << k << " �������" << endl;
	else
	{
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		cout << "����������� ���� " << n << " � " << i << " �� " << k << " �������" << endl;
		hanoi(n - 1, k, tmp);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, k;
	bool a;
	do
	{
		a = true;
		cout << "������� ���-�� ������: " << endl;
		cin >> n;
		cout << "������� ��������� ��������� ������: " << endl;
		cin >> i;
		cout << "������� �������, �� ������� ����� �����������: " << endl;
		cin >> k;
		if (cin.get() != (int)'\n')
		{
			cout << "������������ ����... ��������� ��� ���\n" << endl;
			a = false;
			cin.clear();
			cin.ignore(32444, '\n');
		}
		else if (n < 0 || n > 30 || k <= 1 || k > 3 || i < 1 || i > 3)
		{
			cout << "������������ ����... ��������� ��� ���\n" << endl;
			a = false;
		}
	} while (!a);
	hanoi(n, i, k);
	return 0;
}