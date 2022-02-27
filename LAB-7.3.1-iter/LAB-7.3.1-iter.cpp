// LAB-7.3.1-iter.cpp
// Сушинський Ігор
// Лабораторна робота №7.3.
// Опрацювання динамічних багатовимірних масивів.
// Варіант 18
// Ітераційний спосіб.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Random(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int Part1_Count(int** a, const int k, const int n, int& count);

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 23;

	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Random(a, k, n, Low, High);
	Print(a, k, n);
	int count = 0;

	if (Part1_Count(a, k, n, count))
		cout << "Кiлькiсть = " << count << endl;
	else
		cout << "Немає нульових елементiв" << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Random(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Part1_Count(int** a, const int k, const int n, int& count)
{
	count = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}