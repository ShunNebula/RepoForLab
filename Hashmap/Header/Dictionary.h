#pragma once

#include "../Header/HashTable.h"
#include <iostream>

/// <summary>
/// Класс для работы со словарём.
/// </summary>
class Dictionary
{
private:
	/// <summary>
	/// Хэш-таблица для хранения данных.
	/// </summary>
	HashTable _dictionary;

public:
	/// <summary>
	/// Конструктор словаря.
	/// </summary>
	/// <param name="initialSize">Размер словаря.</param>
	/// <param name="loadFactor">Максимальный коэфициент заполнения.</param>
	Dictionary(size_t initialSize = 11, double loadFactor = 0.75);

	/// <summary>
	/// Добавляет элемент в словарь.
	/// </summary>
	/// <param name="key">Ключ.</param>
	/// <param name="value">Значение элемента.</param>
	void Insert(const std::string& key, const std::string& value);

	/// <summary>
	/// Удаление элементе по ключу.
	/// </summary>
	/// <param name="key">Ключ.</param>
	void Remove(const std::string& key);

	/// <summary>
	/// Поиск значения по ключу.
	/// </summary>
	/// <param name="key">Ключ.</param>
	/// <returns>Искомое значение.</returns>
	std::string Find(const std::string& key);

	/// <summary>
	/// Возвращает размер словаря.
	/// </summary>
	/// <returns>Размер таблицы.</returns>
	size_t GetSize() const;

	/// <summary>
	/// Возвращает количество элементов.
	/// </summary>
	/// <returns>Количество элементов.</returns>
	size_t GetCount() const;

	/// <summary>
	/// Возвращает бакет по индексу в словаре.
	/// </summary>
	/// <param name="index">Получаемый индекс.</param>
	/// <returns>Искомый бакет.</returns>
	Node* GetBucket(size_t index) const;
};