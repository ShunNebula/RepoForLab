#ifndef LIST_H
#define LIST_H

#include "ListItem.h"

template <typename T>
class List
{
private:
	// ��������� �� ������ ������� ������.
	ListItem<T>* head;

	// ��������� �� ��������� ������� ������.
	ListItem<T>* tail;

	// ������ ������.
	size_t size;

public:
	// �����������.
	List();

	// ����������.
	~List();

	// �������� ������ ������.
	size_t GetSize() const;

	// �������� ������� � ������ ������.
	void AddStart(const T& value);

	// �������� ������� � ����� ������.
	void AddEnd(const T& value);

	// �������� ������� ����� ��������� ����.
	void InsertAfter(ListItem<T>* node, const T& value);

	// �������� ������� ����� �������� �����.
	void InsertBefore(ListItem<T>* node, const T& value);

	// ������� �������� ���� �� ������.
	void Remove(ListItem<T>* node);

	// ���������� ������.
	void Sort();

	// �������� ����� �������� � ������.
	ListItem<T>* LinerSearch(const T& value);

	// ����� ������.
	void Print() const;

	// �������� ������ (��� �����������).
	void Clear();


	void AddStartBenchmark(int size);
	void AddEndBenchmark(int size);
	void RemoveBenchmark(int size);
	void InsertAfterBenchmark(ListItem<T>* node, const T& value, int size);
	void InsertBeforeBenchmark(ListItem<T>* node, const T& value, int size);
};

#endif#pragma once
