#include <iostream>

using namespace std;

void hanoi(int n, int i, int k)
{
	if (n == 1)
		cout << "Переместите диск 1 с " << i << " на " << k << " столбик" << endl;
	else
	{
		int tmp = 6 - i - k;
		hanoi(n - 1, i, tmp);
		cout << "Переместите диск " << n << " с " << i << " на " << k << " столбик" << endl;
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
		cout << "Введите кол-во дисков: " << endl;
		cin >> n;
		cout << "Введите начальное положение дисков: " << endl;
		cin >> i;
		cout << "Введите столбик, на который нужно переместить: " << endl;
		cin >> k;
		if (cin.get() != (int)'\n')
		{
			cout << "Некорректный ввод... Повторите еще раз\n" << endl;
			a = false;
			cin.clear();
			cin.ignore(32444, '\n');
		}
		else if (n < 0 || n > 30 || k <= 1 || k > 3 || i < 1 || i > 3)
		{
			cout << "Некорректный ввод... Повторите еще раз\n" << endl;
			a = false;
		}
	} while (!a);
	hanoi(n, i, k);
	return 0;
}