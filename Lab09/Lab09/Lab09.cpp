// C++ implementation of the above approach
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


#define NumofCity 5
#define CHILD 3
#define START 0
#define POP_SIZE 5


int map[NumofCity][NumofCity] = { 
				{ INT_MAX, 25, 40, 31, 27},
				{ 5, INT_MAX, 17, 30, 25},
				{ 19, 15, INT_MAX, 6, 1},
				{ 9, 50, 24, INT_MAX, 6 },
				{ 22, 8, 7, 10, INT_MAX } };
struct individual {
	string Genom;
	int lenpath;
};


int rand_num(int start, int end)
{
	int r = end - start;
	int rnum = start + rand() % r;
	return rnum;
}


bool RepeatTown(string s, char ch)
{
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ch)
			return true;
	}
	return false;
}


string mutatedGene(string genom)
{
	while (true) {
		int r = rand_num(1, NumofCity);
		int r1 = rand_num(1, NumofCity);
		if (r1 != r) {
			char temp = genom[r];
			genom[r] = genom[r1];
			genom[r1] = temp;
			break;
		}
	}
	return genom;
}

string Create_genome()
{
	string genom = "0";
	while (true) {
		if (genom.size() == NumofCity) {
			genom += genom[0];
			break;
		}
		int temp = rand_num(1, NumofCity);
		if (!RepeatTown(genom, (char)(temp + 48)))
			genom += (char)(temp + 48);
	}
	return genom;
}

int Count_Path(string genom)
{
	int f = 0;
	for (int i = 0; i < genom.size() - 1; i++) {
		if (map[genom[i] - 48][genom[i + 1] - 48] == INT_MAX)
			return INT_MAX;
		f += map[genom[i] - 48][genom[i + 1] - 48];
	}
	return f;
}

int cooldown(int temp)
{
	return (90 * temp) / 100;
}

bool lessthan(struct individual t1,
	struct individual t2)
{
	return t1.lenpath < t2.lenpath;
}

void TSPUtil(int map[NumofCity][NumofCity])
{
	int gen = 1;
	int gen_thres = 54;

	vector<struct individual> population;
	struct individual temp;

	for (int i = 0; i < POP_SIZE; i++) {
		temp.Genom = Create_genome();
		temp.lenpath = Count_Path(temp.Genom);
		population.push_back(temp);
	}

	cout << "\n---Начальная популяция---\n" << endl
		<< "Геном         Значение пути\n";
	for (int i = 0; i < POP_SIZE; i++)
		cout << population[i].Genom << "\t\t"
		<< population[i].lenpath << endl;
	cout << "\n";

	int temperature = 2000;

	sort(population.begin(), population.end(), lessthan);

	while (temperature > 100 && gen <= gen_thres) {
		cout << endl << "Лучший Ген " << population[0].Genom << endl;
		cout << endl << "Лучший путь " << population[0].lenpath << endl;

		vector<struct individual> new_population;

		for (int i = 0; i < CHILD; i++) {

			struct individual p1 = population[i];

			while (true)
			{
				string new_g = mutatedGene(p1.Genom);
				struct individual new_genom;
				new_genom.Genom = new_g;
				new_genom.lenpath = Count_Path(new_genom.Genom);

				if (new_genom.lenpath <= population[i].lenpath) {
					new_population.push_back(new_genom);
					break;
				}
				else {
					new_genom.lenpath = INT_MAX;
					new_population.push_back(new_genom);
					break;
				}
			}
		}

		temperature = cooldown(temperature);
		for (int i = 0; i < CHILD; i++)
		{
			population.push_back(new_population[i]);
		}
		sort(population.begin(), population.end(), lessthan);

		for (int i = 0; i < CHILD; i++)
		{
			population.pop_back();
		}

		cout << "---Поколение--- \n" << "#" << gen << " \n";
		cout << "Геном:	   Длина пути:\n";

		for (int i = 0; i < POP_SIZE; i++)
			cout << population[i].Genom << "\t\t"
			<< population[i].lenpath << endl;
		gen++;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	TSPUtil(map);
}
