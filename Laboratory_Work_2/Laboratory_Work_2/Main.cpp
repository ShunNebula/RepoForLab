#include "List.h"
#include "iostream"
#include <iomanip> 

/// <summary>
/// Функция для проведения бенчмарк-тестов различных операций со списком.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
/// <param name="myList">Список для тестирования.</param>
/// <param name="size">Количество элементов для использования в тестах.</param>
template<typename T>
void BenchmarkTest(List<T>& myList, int size)
{
	myList.FillBenchmark(size);

	double removeTime = myList.Benchmark(myList.RemoveBenchmark(size), size, "Remove");
	std::cout << "Время удаления " << size << " элементов(Remove): " << std::fixed << std::setprecision(6) << removeTime << " секунд." << std::endl;
	myList.Clear();

	double addStartTime = myList.Benchmark(myList.AddBenchmark(size, true), size, "AddStart");
	std::cout << "Время добавления " << size << " элементов(AddStart): " << std::fixed << std::setprecision(6) << addStartTime << " секунд" << std::endl;
	myList.Clear();

	double addEndTime = myList.Benchmark(myList.AddBenchmark(size, false), size, "AddEnd");
	std::cout << "Время добавления " << size << " элементов(AddEnd): " << std::fixed << std::setprecision(6) << addEndTime << " секунд" << std::endl;
	myList.Clear();

	myList.Add(5, false);
	ListItem<T>* nodeInsertAfter = myList.LinearSearch(5);
	double insertAfterTime = myList.Benchmark(myList.InsertBenchmark(nodeInsertAfter, size, true), size, "InsertAfter");
	std::cout << "Время добавления " << size << " элементов(InsertAfter): " << std::fixed << std::setprecision(6) << insertAfterTime << " секунд" << std::endl;
	myList.Clear();

	myList.Add(5, true); 
	ListItem<T>* nodeInsertBefore = myList.LinearSearch(5);
	double insertBeforeTime = myList.Benchmark(myList.InsertBenchmark(nodeInsertBefore, size, false), size, "InsertBefore");
	std::cout << "Время добавления " << size << " элементов(InsertBefore): " << std::fixed << std::setprecision(6) << insertBeforeTime << " секунд" << std::endl;
	myList.Clear();
}

/// <summary>
/// Выводит элементы списка в консоль.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
/// <param name="myList">Список для вывода.</param>
template<typename T>
void PrintList(const List<T>& myList) 
{
	ListItem<T>* current = myList.GetHead();
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


int main()
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
				  myList.Add(value, true);
				  break;
		}
		case 2:
		{
				  int value;
				  std::cout << "Введите значение для добавления в конец: ";
				  std::cin >> value;
				  myList.Add(value, false);
				  break;
		}
		case 3:
		{
				  int value, node;
				  std::cout << "Введите значение для добавления после элемента: ";
				  std::cin >> value;
				  std::cout << "Введите значение элемента, после которого вставлять: ";
				  std::cin >> node;
				  ListItem<int>* nodeInsertAfter = myList.LinearSearch(node);
				  if (nodeInsertAfter)
				  {
					  myList.Insert(nodeInsertAfter, value, true);
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
				  ListItem<int>* nodeInsertBefore = myList.LinearSearch(node);
				  if (nodeInsertBefore)
				  {
					  myList.Insert(nodeInsertBefore, value, false);
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
				  ListItem<int>* nodeFind = myList.LinearSearch(node);
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
				  if (myList.LinearSearch(node))
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
			PrintList(myList);
			break;
		}
		case 9:
		{
			BenchmarkTest<int>(myList, 10);
			BenchmarkTest<int>(myList, 100);
			BenchmarkTest<int>(myList, 1000);
			BenchmarkTest<int>(myList, 10000);
			BenchmarkTest<int>(myList, 100000);
			break;
		}
		default:
			std::cout << "Неверный выбор." << std::endl;
		}
	}
}