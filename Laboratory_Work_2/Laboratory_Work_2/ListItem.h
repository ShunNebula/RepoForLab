#pragma once
#ifndef LISTITEM_H
#define LISTITEM_H

#include <iostream>

template <typename T>
struct ListItem
{
	// ������, ���������� � �������� ������.
	T data;

	// ��������� �� ���������� ������� ������.
	ListItem<T>* prev;

	// ��������� �� ��������� ������� ������.
	ListItem<T>* next;

	// �����������
	ListItem(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif