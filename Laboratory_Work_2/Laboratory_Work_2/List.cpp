#include "List.h"
#include <chrono>
#include <iomanip>

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::~List()
{
	Clear();
}

template <typename T>
size_t List<T>::GetSize() const
{
	return size;
}

template <typename T>
void List<T>::Clear()
{
	ListItem<T>* current = head;
	while (current != nullptr)
	{
		ListItem<T>* next = current->next;
		delete current;
		current = next;
	}
	head = tail = nullptr;
	size = 0;
}

template <typename T>
void List<T>::AddStart(const T& value)
{
	ListItem<T>* newNode = new ListItem<T>(value);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	size++;
}

template <typename T>
void List<T>::AddEnd(const T& value)
{
	ListItem<T>* newNode = new ListItem<T>(value);
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

template <typename T>
void List<T>::InsertAfter(ListItem<T>* node, const T& value)
{
	if (node == nullptr)
	{
		AddStart(value);
		return;
	}

	if (node == tail)
	{
		AddEnd(value);
		return;
	}

	ListItem<T>* newNode = new ListItem<T>(value);
	newNode->next = node->next;
	newNode->prev = node;
	node->next->prev = newNode;
	node->next = newNode;

	size++;
}

template <typename T>
void List<T>::InsertBefore(ListItem<T>* node, const T& value)
{
	if (node == nullptr)
	{
		AddEnd(value);
		return;
	}

	if (node == head)
	{
		AddStart(value);
		return;
	}

	ListItem<T>* newNode = new ListItem<T>(value);
	newNode->prev = node->prev;
	newNode->next = node;
	node->prev->next = newNode;
	node->prev = newNode;

	size++;
}

template <typename T>
void List<T>::Remove(ListItem<T>* node)
{
	if (!node) return;

	if (node == head)
	{
		head = node->next;
		if (head)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
	}
	else if (node == tail)
	{
		tail = node->prev;
		tail->next = nullptr;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	delete node;
	size--;
}

template <typename T>
ListItem<T>* List<T>::LinerSearch(const T& value)
{
	ListItem<T>* current = head;
	while (current != nullptr)
	{
		if (current->data == value)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

template <typename T>
void List<T>::Sort()
{
	if (size <= 1) return;

	bool swapped = true;
	ListItem<T>* ptr1;
	ListItem<T>* lptr = nullptr;

	do
	{
		swapped = false;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				std::swap(ptr1->data, ptr1->next->data);
				swapped = true;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

template <typename T>
void List<T>::Print() const
{
	ListItem<T>* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::AddStartBenchmark(int size)
{
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < size; ++i) // повторить операцию много раз
	{
		AddStart(i);
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Время добавления " << size << " элементов(AddStart): " << elapsed.count() << " секунд" << std::endl;
}

template <typename T>
void List<T>::AddEndBenchmark(int size)
{
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < size; ++i) // повторить операцию много раз
	{
		AddEnd(i);
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Время добавления " << size << " элементов(AddEnd): " << elapsed.count() << " секунд" << std::endl;
}

template <typename T>
void List<T>::InsertAfterBenchmark(ListItem<T>* node, const T& value, int size) 
{
	if (!node && head) { // Если node == nullptr и список не пуст, вставляем после head
		node = head;
	}
	if (!node) return;

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < size; ++i) // повторить операцию много раз
	{
		InsertAfter(node, i);
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Время добавления " << size << " элементов(InsertAfter): " << elapsed.count() << " секунд" << std::endl;
}

template <typename T>
void List<T>::InsertBeforeBenchmark(ListItem<T>* node, const T& value, int size) {
	if (!node && head) { // Если node == nullptr и список не пуст, вставляем перед head
		node = head;
	}
	if (!node) return;

	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < size; ++i) // повторить операцию много раз
	{
		InsertBefore(node, i);
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Время добавления " << size << " элементов(InsertBefore): " << elapsed.count() << " секунд" << std::endl;
}

template <typename T>
void List<T>::RemoveBenchmark(int size) 
{
	for (int i = 0; i < size; i++)
	{
		AddEnd(i);
	}

	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < size; i++)
	{
		Remove(LinerSearch(i));
	}
	
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Время удаления " << size << " элементов(Remove): " << elapsed.count() << " секунд." << std::endl;
}