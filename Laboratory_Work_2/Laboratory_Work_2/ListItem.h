#pragma once
#ifndef LISTITEM_H
#define LISTITEM_H

#include <iostream>

template <typename T>
struct ListItem
{
	// Данные, хранящиеся в элементе списка.
	T data;

	// Указатель на предыдущий элемент списка.
	ListItem<T>* prev;

	// Указатель на следующий элемент списка.
	ListItem<T>* next;

	// Конструктор
	ListItem(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

#endif