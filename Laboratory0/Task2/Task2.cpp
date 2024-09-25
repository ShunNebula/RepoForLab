#include <iostream>

using namespace std;

void writeArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}
void writeArray(double array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}
void writeArray(char array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void subTask1()
{
	int const n = 10;
	int array[n] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

	cout << "Source array is:" << endl;

	writeArray(array, n);

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

	cout << endl << "Sorted array is:" << endl;

	writeArray(array, n);
}

void subTask2()
{
	int const n = 12;
	double array[n] = { 12.0, 21.5, 119.2, - 80.7, 300.0, 75.5, 81.2, 8.1, 47.3, 31.2, 85.3, 100.1};

	cout << "Source array is:" << endl;

	writeArray(array, n);

	double searchingValue;
	cout << endl << "Enter searching value:";
	cin >> searchingValue;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] >= searchingValue)
			count++;
	}

	cout << "Elements of array more than " << searchingValue << " is: " << count;
}

void subTask3()
{
	int const n = 8;
	char array[n];

	cout << "Enter array of 8 chars" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		char newSymbol;
		cin >> newSymbol;
		array[i] = newSymbol;
	}

	cout << "Your array is:" << endl;
	writeArray(array, n);

	cout << "All letters in your array:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z' || array[i] >= 'A' && array[i] <= 'Z')
		{
			cout << array[i] << " ";
		}
	}
}

int main()
{
	subTask3();
}