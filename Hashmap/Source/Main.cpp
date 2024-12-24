#include "../Header/Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// ������� ��� �������� ����� ������ ����� �������������.
/// ������� ����������� � ������������ ���� ������ ����� � ���������� ������ �� ��� ���,
/// ���� �� ����� ������� ���������� ��������.
/// </summary>
/// <returns>��������� ������������� ����� �����.</returns>
int CheckValue()
{
	cout << "��� ����: ";

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
					cout << "������� �������� �������� (���������� �������). ��������� ����: ";
				}
			}
			catch (const invalid_argument& e)
			{
				cout << "������� �������� �������� (�� �����). ��������� ����: ";
			}
			catch (const out_of_range& e)
			{
				cout << "������� ������� ������� ��������. ��������� ����: ";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "������ �����. ��������� ����: ";
		}
	}
}

/// <summary>
/// ����� ���-�������.
/// </summary>
/// <param name="dict">�������.</param>
void PrintTable(const Dictionary& dict)
{
	cout << "���-�������:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		cout << i << ": ";
		Node* current = dict.GetBucket(i);
		
		if (current == nullptr)
		{
			cout << "�����";
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
/// ����� �������.
/// </summary>
/// <param name="dict">�������.</param>
void PrintDictionary(const Dictionary& dict)
{
	cout << "�������:" << endl;
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
		cout << endl << "����" << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ����� �������" << endl;
		cout << "4. ������� ���-�������" << endl;
		cout << "5. ������� �������" << endl;
		cout << "0. �����" << endl;
		
		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			cout << "������� ����: ";
			cin >> key;
			cout << "������� ��������: ";
			cin >> value;
			dict.Insert(key, value);
			cout << "������� ��������.\n";
			break;
		}
		case 2:
		{
			cout << "������� ���� ��� ��������: ";
			cin >> key;
			dict.Remove(key);
			break;
		}
		case 3:
		{
			cout << "������� ���� ��� ������: ";
			cin >> key;
			value = dict.Find(key);
			if (value != "")
			{
				cout << "��������: " << value << endl;
			}
			else
			{
				cout << "������� �� ������.\n";
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
			cout << "�����...\n";
			break;
		}
		default:
		{
			cout << "�������� �����.\n";
		}
		}
	} while (choice != 0);

	return 0;
}