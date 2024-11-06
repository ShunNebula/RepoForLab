#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

template <typename T>
class List
{
private:
	// Указатель на первый элемент списка.
	ListItem<T>* head;

	// Указатель на последний элемент списка.
	ListItem<T>* tail;

	// Размер списка.
	size_t size;

public:
	// Конструктор.
	List();

	// Деструктор.
	~List();

	// Получить размер списка.
	size_t GetSize() const;

	// Добавить элемент в начало списка.
	void AddStart(const T& value);

	// Добавить элемент в конец списка.
	void AddEnd(const T& value);

	// Вставить элемент после заданного узла.
	void InsertAfter(ListItem<T>* node, const T& value);

	// Вставить элемент перед заданным узлом.
	void InsertBefore(ListItem<T>* node, const T& value);

	// Удалить заданный узел из списка.
	void Remove(ListItem<T>* node);

	// Сортировка списка.
	void Sort();

	// Линейный поиск элемента в списке.
	ListItem<T>* LinerSearch(const T& value);

	// Вывод списка.
	void Print() const;

	// Очистить список (для деструктора).
	void Clear();


	void AddStartBenchmark(int size);
	void AddEndBenchmark(int size);
	void RemoveBenchmark(int size);
	void InsertAfterBenchmark(ListItem<T>* node, const T& value, int size);
	void InsertBeforeBenchmark(ListItem<T>* node, const T& value, int size);
};

#endif#pragma once
