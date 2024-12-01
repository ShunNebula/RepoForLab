#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueRingBuffer.h"
#include "QueueTwoStacks.h"


/**
 * @brief Проверяет вводимое значение.
 * @return Проверенное значение.
 *
 * @details Значение должно быть целым числом.
 */
int CheckValue() {
	int value;
	while (true) 
	{
		std::cout << "Ваш ввод: ";
		if (std::cin >> value) 
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			return value;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Введено неверное значение. Повторите ввод: ";
		}
	}
}

/**
* @brief Выводит меню и обрабатывает ввод пользователя для выбранной структуры данных.
*
* @param data Данные для отображения.
* @param typeName Имя типа данных.
*/
void Print(const std::vector<int>& data, const std::string& typeName)
{
	std::cout << std::endl << "Элементы " << typeName << ":" << std::endl;
	for (int x : data)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl << std::endl << "Выберите команду:" << std::endl;
	std::cout << "0. Выйти в меню" << std::endl;
	std::cout << "1. Добавить (Push/Enqueue) элемент в " << typeName << std::endl;
	std::cout << "2. Достать (Pop/Dequeue) элемент из " << typeName << std::endl;
}

/**
* @brief Меню для работы со стеком.
*/
void StackMenu()
{
	Stack<int>* stack = new Stack<int>();

	int choice;
	do
	{
		std::string typeName = "Stack";
		std::vector<int> stackData = stack->GetData();

		Print(stackData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			int value;
			std::cout << "Введите значение для элемента: ";
			value = CheckValue();
			stack->Push(value);
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Взятый элемент: " << stack->Pop() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Ошибка: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete stack;
			std::cout << "Выход в меню..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Неизвестное значение." << std::endl;
		}
		}
	} while (choice != 0);
}


/**
* @brief Меню для работы с кольцевым буфером.
*/
void RingBufferMenu()
{
	RingBuffer<int>* buffer = new RingBuffer<int>(5);

	int choice;
	do
	{
		std::string typeName = "RingBuffer";
		std::vector<int> bufferData = buffer->GetData();

		Print(bufferData, typeName);

		std::cout << "3. Свободное место" << std::endl;
		std::cout << "4. Занятое место" << std::endl;

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			try
			{
				int value;
				std::cout << "Введите значение для элемента: ";
				value = CheckValue();
				buffer->Push(value);
			}
			catch (const std::overflow_error& error)
			{
				std::cout << error.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Взятый элемент: " << buffer->Pop() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Ошибка: " << error.what() << std::endl;
			}
			break;
		}
		case 3:
		{
			std::cout << "Свободное место: " << buffer->FreeSpace() << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Занятое место: " << buffer->UsedSpace() << std::endl;
			break;
		}
		case 0:
		{
			delete buffer;
			std::cout << "Выход в меню..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Неизвестное значение." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Меню для работы с очередью на основе кольцевого буфера.
*/
void QueueRingBufferMenu()
{
	QueueRingBuffer<int>* queue = new QueueRingBuffer<int>(5);

	int choice;
	do
	{
		std::string typeName = "QueueRingBuffer";
		std::vector<int> queueData = queue->GetData();

		Print(queueData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			try
			{
				int value;
				std::cout << "Введите значение для элемента: ";
				value = CheckValue();
				queue->Enqueue(value);
			}
			catch (const std::overflow_error& error)
			{
				std::cout << error.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Взятый элемент: " << queue->Dequeue() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Ошибка: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete queue;
			std::cout << "Выход в меню..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Неизвестное значение." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Меню для работы с очередью на основе двух стеков.
*/
void QueueTwoStacksMenu()
{
	QueueTwoStacks<int>* queue = new QueueTwoStacks<int>();

	int choice;
	do
	{
		std::string typeName = "QueueTwoStacks";
		std::vector<int> queueData = queue->GetData();

		Print(queueData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			int value;
			std::cout << "Введите значение для элемента: ";
			value = CheckValue();
			queue->Enqueue(value);
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Взятый элемент: " << queue->Dequeue() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Ошибка: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete queue;
			std::cout << "Выход в меню..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Неизвестная команда. Попробуйте еще раз." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Главное меню программы.
*/
int main()
{
	setlocale(LC_ALL, "");

	int menuChoice;
	do
	{
		std::cout << std::endl;
		std::cout << std::endl << "Меню" << std::endl;
		std::cout << "1. Стек" << std::endl;
		std::cout << "2. Кольцевой буфер" << std::endl;
		std::cout << "3. Очередь на основе кольцевого буфера" << std::endl;
		std::cout << "4. Очередь на основе двух стеков" << std::endl;
		std::cout << "0. Выход" << std::endl;

		menuChoice = CheckValue();

		switch (menuChoice)
		{
		case 1:
		{
			StackMenu();
			break;
		}
		case 2:
		{
			RingBufferMenu();
			break;
		}
		case 3:
		{
			QueueRingBufferMenu();
			break;
		}
		case 4:
		{
			QueueTwoStacksMenu();
			break;
		}
		case 0:
		{
			std::cout << "Выход..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Неизвестная команда. Попробуйте еще раз." << std::endl;
		}
		}
	} while (menuChoice != 0);

	return 0;
}