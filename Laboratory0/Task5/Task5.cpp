#include <iostream>

using namespace std;

void writeArray(double array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}
void writeArray(bool array[], int n)
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
		std::cout << array[i] << " ";
	}
}
void writeArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void subTask1()
{
	int const n = 8;
	double* array = new double[n] {1.0, 15.0, - 8.2, - 3.5, 12.6, 38.4, - 0.5, 4.5};

	cout << "Array of double:" << endl;

	writeArray(array, n);

	delete[] array;
}

void subTask2()
{
	int const n = 8;
	bool* array = new bool[n] {1, 1, 1, 1, 0, 0, 0, 0};

	cout << "Array of double:" << endl;

	writeArray(array, n);

	delete[] array;
}

void subTask3()
{
	cout << "Enter char array size: ";
	int n;
	cin >> n;
	char* array = new char[n];

	for (int i = 0; i < n; i++)
	{
		char newSymbol;
		cout << "Enter a[" << i << "]: ";
		cin >> newSymbol;
		array[i] = newSymbol;
	}

	cout << endl << "Your char array is:" << endl;

	writeArray(array, n);

	delete[] array;
}

void subTask4()
{
	int const n = 10;
	double* array = new double[n] { 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5 };

	cout << "Array of double:" << endl;

	writeArray(array, n);

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				double temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

	cout << endl << "Sorted array of double:" << endl;

	writeArray(array, n);

	delete[] array;
}

void subTask5()
{
	int const n = 10;
	int* array = new int[n] { 1, 15, - 8, - 3, 12, 38, 0, 4, 16, 4 };

	cout << "Int array:" << endl;

	writeArray(array, n);

	double searchingValue;
	cout << endl << endl << "Enter searching value: ";
	cin >> searchingValue;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] >= searchingValue)
			count++;
	}

	cout << endl << "Index of searching value " << searchingValue << " is: " << count;

	delete[] array;
}

void subTask6()
{
	int const n = 15;
	char* array = new char[n] { 'a', '5', 'm', 'i', '%', '!', 's', 'p', '*', '9', 'f', '^', ';', 'q', 'k' };

	std::cout << "Char array is:" << endl;

	writeArray(array, n);

	std::cout << endl << "Letters in array:" << endl;

	for (int i = 0; i < n; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z' || array[i] >= 'A' && array[i] <= 'Z')
		{
			std::cout << array[i] << " ";
		}
	}
}

int* MakeRandomArray(int arraySize)
{
	int* array = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 100;
	}
	return array;
}

void subTask7()
{
	cout << "Random array of 5:" << endl;
	int* array5 = MakeRandomArray(5);
	writeArray(array5, 5);

	cout << endl << endl << "Random array of 8:" << endl;
	int* array8 = MakeRandomArray(8);
	writeArray(array8, 8);

	cout << endl << endl << "Random array of 13:" << endl;
	int* array13 = MakeRandomArray(13);
	writeArray(array13, 13);

	delete[] array5;
	delete[] array8;
	delete[] array13;
}


// Утечка памяти
int* ReadArray(int count)
{
	int* values = new int[count];
	for (int i = 0; i < count; i++)
	{
	cin >> values[i];
	}
	return values;
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}
	return result;
}

void subTask8()
{
	int count = 15;
	int* values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;
	
	// Утечка памяти происходит из-за того, что выделенная память 
	// не освобождается до delete[], а вместо этого переназначается 
	// и выделенная память теряется.

	count = 20;
	values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;
	
	delete[] values;
}

// Ответьте на вопрос : какие примеры некорректной работы с кодом / синтаксическими
// конструкциями вы можете отметить в предыдущем участке кода ?

// 1. утечка памяти
// 2. нет проверки ошибок при вводе


int main()
{
	subTask7();
}