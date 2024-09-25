#include <iostream>

using namespace std;

// Задание #1
void Breakpoints1()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += add * i;
		add *= 1.1;
	}
	cout << "Total sum is " << sum << endl;
}

// sum
// 0.0000000000000000
// 1.1000000000000001
// 3.5200000000000005
// 7.5130000000000017
// 13.369400000000004
// 21.421950000000010
// 32.051316000000014
// 45.692335700000022
// 62.841046180000035
// 84.062575399000053

void Breakpoints2()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; // Поставьте условную точку останова здесь
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}
	cout << "Total sum is " << sum << endl;
}

// sum
// 3.2624579394327844


int main()
{
	Breakpoints2();
}