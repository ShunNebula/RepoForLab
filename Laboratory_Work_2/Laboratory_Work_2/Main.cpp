#include "List.h"
#include "List.cpp"
#include "iostream"

template<typename T>
void BenchmarkTest(List<T>& myList, int size, T insertValue)
{
	myList.RemoveBenchmark(size);
	myList.Clear();

	myList.AddStartBenchmark(size);
	myList.Clear();

	myList.AddEndBenchmark(size); 
	myList.Clear();

	myList.AddEnd(5);
	myList.InsertAfterBenchmark(myList.LinerSearch(insertValue), insertValue + 5, size); 
	myList.Clear();

	myList.AddEnd(5);
	myList.InsertBeforeBenchmark(myList.LinerSearch(insertValue), insertValue + 7, size); 
	myList.Clear();
}

void main()
{
	List<int> myList;

	setlocale(LC_ALL, "Russian");

	std::cout << "Выберите действие:" << std::endl;
	std::cout << "0. Вывести инструкции." << std::endl;
	std::cout << "1. Добавить в начало." << std::endl;
	std::cout << "2. Добавить в конец." << std::endl;
	std::cout << "3. Вставить после элемента." << std::endl;
	std::cout << "4. Вставить перед элементом." << std::endl;
	std::cout << "5. Удалить элемент." << std::endl;
	std::cout << "6. Сортировать." << std::endl;
	std::cout << "7. Линейный поиск." << std::endl;
	std::cout << "8. Вывести список." << std::endl;
	std::cout << "9. Вывод времени." << std::endl;

	int choice;
	while (true)
	{
		std::cout << std::endl << "Введите номер действия: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
				  std::cout << "0. Вывести инструкции." << std::endl;
				  std::cout << "1. Добавить в начало." << std::endl;
				  std::cout << "2. Добавить в конец." << std::endl;
				  std::cout << "3. Вставить после элемента." << std::endl;
				  std::cout << "4. Вставить перед элементом." << std::endl;
				  std::cout << "5. Удалить элемент." << std::endl;
				  std::cout << "6. Сортировать." << std::endl;
				  std::cout << "7. Линейный поиск." << std::endl;
				  std::cout << "8. Вывести список." << std::endl;
				  std::cout << "9. Вывод времени." << std::endl;
				  break;
		}
		case 1:
		{
				  int value;
				  std::cout << "Введите значение для добавления в начало: ";
				  std::cin >> value;
				  myList.AddStart(value);
				  break;
		}
		case 2:
		{
				  int value;
				  std::cout << "Введите значение для добавления в конец: ";
				  std::cin >> value;
				  myList.AddEnd(value);
				  break;
		}
		case 3:
		{
				  int value, node;
				  std::cout << "Введите значение для добавления после элемента: ";
				  std::cin >> value;
				  std::cout << "Введите значение элемента, после которого вставлять: ";
				  std::cin >> node;
				  ListItem<int>* nodeInsertAfter = myList.LinerSearch(node);
				  if (nodeInsertAfter)
				  {
					  myList.InsertAfter(nodeInsertAfter, value);
				  }
				  else
				  {
				  std::cout << "Элемент не найден." << std::endl;
				  }
				  break;
		}
		case 4:
		{
				  int value, node;
				  std::cout << "Введите значение для добавления перед элементом: ";
				  std::cin >> value;
				  std::cout << "Введите значение элемента, перед которым вставлять: ";
				  std::cin >> node;
				  ListItem<int>* nodeInsertBefore = myList.LinerSearch(node);
				  if (nodeInsertBefore)
				  {
					  myList.InsertBefore(nodeInsertBefore, value);
				  }
				  else
				  {
					  std::cout << "Элемент не найден." << std::endl;
				  }
				  break;
		}
		case 5:
		{
				  int node;
				  std::cout << "Введите значение элемента для удаления: ";
				  std::cin >> node;
				  ListItem<int>* nodeFind = myList.LinerSearch(node);
				  if (nodeFind)
				  {
					  myList.Remove(nodeFind);
				  }
				  else
				  {
					  std::cout << "Элемент не найден." << std::endl;
				  }
				  break;
		}
		case 6:
		{
				  myList.Sort();
				  std::cout << "Спсиок отсортирован." << std::endl;
				  break;
		}
		case 7:
		{
				  int node;
				  std::cout << "Введите значение для поиска: ";
				  std::cin >> node;
				  if (myList.LinerSearch(node))
				  {
				  std::cout << "Элемент найден." << std::endl;
				  }
				  else
				  {
				  std::cout << "Элемент не найден." << std::endl;
				  }
				  break;
		}
		case 8:
		{
				  std::cout << std::endl << "Список:" << std::endl;
				  myList.Print();
				  break;
		}
		case 9:
		{
			BenchmarkTest<int>(myList, 10, 5);
			BenchmarkTest<int>(myList, 100, 50);
			BenchmarkTest<int>(myList, 1000, 500);
			BenchmarkTest<int>(myList, 10000, 5000);
			BenchmarkTest<int>(myList, 100000, 50000);
			break;
		}
		default:
			std::cout << "Неверный выбор." << std::endl;
		}
	}
}