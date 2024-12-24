#include "../Header/Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Функция для проверки ввода целого числа пользователем.
/// Функция запрашивает у пользователя ввод целого числа и продолжает запрос до тех пор,
/// пока не будет введено корректное значение.
/// </summary>
/// <returns>Введенное пользователем целое число.</returns>
int CheckValue()
{
	cout << "Ваш ввод: ";

	string input;
	while (true)
	{
		if (cin >> input)
		{
			try
			{
				size_t pos;
				int value = stoi(input, &pos);
				if (pos == input.length())
				{
					return value;
				}
				else
				{
					cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
				}
			}
			catch (const invalid_argument& e)
			{
				cout << "Введено неверное значение (не число). Повторите ввод: ";
			}
			catch (const out_of_range& e)
			{
				cout << "Введено слишком большое значение. Повторите ввод: ";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ошибка ввода. Повторите ввод: ";
		}
	}
}

/// <summary>
/// Вывод хэш-таблицы.
/// </summary>
/// <param name="dict">Словарь.</param>
void PrintTable(const Dictionary& dict)
{
	cout << "Хэш-таблица:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		cout << i << ": ";
		Node* current = dict.GetBucket(i);
		
		if (current == nullptr)
		{
			cout << "Пусто";
		}
		else
		{
			for (; current != nullptr; current = current->next)
			{
				cout << "[" << current->key << "] -> " << current->value;
				if (current->next != nullptr)
				{
					cout << "; ";
				}
			}
		}

		cout << endl;
	}
}

/// <summary>
/// Вывод словаря.
/// </summary>
/// <param name="dict">Словарь.</param>
void PrintDictionary(const Dictionary& dict)
{
	cout << "Словарь:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		Node* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->next)
		{
			std::cout << current->key << ": " << current->value << std::endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Dictionary dict;

	int choice;
	string key;
	string value;

	do
	{
		cout << endl << "Меню" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Найти элемент" << endl;
		cout << "4. Вывести хеш-таблицу" << endl;
		cout << "5. Вывести словарь" << endl;
		cout << "0. Выход" << endl;
		
		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			cout << "Введите ключ: ";
			cin >> key;
			cout << "Введите значение: ";
			cin >> value;
			dict.Insert(key, value);
			cout << "Элемент добавлен.\n";
			break;
		}
		case 2:
		{
			cout << "Введите ключ для удаления: ";
			cin >> key;
			dict.Remove(key);
			break;
		}
		case 3:
		{
			cout << "Введите ключ для поиска: ";
			cin >> key;
			value = dict.Find(key);
			if (value != "")
			{
				cout << "Значение: " << value << endl;
			}
			else
			{
				cout << "Элемент не найден.\n";
			}
			break;
		}
		case 4:
		{
			PrintTable(dict);
			break;
		}
		case 5:
		{
			PrintDictionary(dict);
			break;
		}
		case 0:
		{
			cout << "Выход...\n";
			break;
		}
		default:
		{
			cout << "Неверный выбор.\n";
		}
		}
	} while (choice != 0);

	return 0;
}