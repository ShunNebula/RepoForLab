#pragma once

#include <iostream>

// TODO: Один класс/структура - один файл
/// <summary>
/// Структура для хранения пары ключ-значение.
/// </summary>
struct Node
{
	/// <summary>
	/// Ключ.
	/// </summary>
	std::string key;

	/// <summary>
	/// Значение.
	/// </summary>
	std::string value;

	/// <summary>
	/// Указатель на следующую пару.
	/// </summary>
	Node* next;

	/// <summary>
	/// Конструктор элемента словаря (ключ-значение).
	/// </summary>
	/// <param name="k">Ключ.</param>
	/// <param name="v">Значение.</param>
	Node(const std::string& k, const std::string v) : key(k), value(v), next(nullptr) {}
};