#pragma once

#include "stack.h"

/**
* @brief Шаблонный класс для реализации очереди с использованием двух стеков.
* @tparam T Тип данных, хранящихся в очереди.
*/
template <typename T>
class QueueTwoStacks
{
private:
	/** @brief Первый стек, используемый для добавления элементов. */
	Stack<T> _stack1;

	/** @brief Второй стек, используемый для извлечения элементов. */
	Stack<T> _stack2;

public:
	/**
	* @brief Проверка на пустоту очереди.
	* @return true, если очередь пуста; false в противном случае.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsEmpty() && _stack2.IsEmpty();
	}

	/**
	* @brief Возвращает размер очереди.
	* @return Размер очереди.
	*/
	size_t GetSize() const
	{
		return _stack1.GetSize() + _stack2.GetSize();
	}

	/**
	* @brief Добавление элемента в очередь.
	* @param data Элемент, который нужно добавить.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	/**
	* @brief Извлечение элемента из очереди.
	* @return Элемент, извлеченный из очереди.
	* @throw std::underflow_error Если очередь пуста.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Очередь пуста!");
		}
		if (_stack2.IsEmpty())
		{
			while (!_stack1.IsEmpty())
			{
				_stack2.Push(_stack1.Pop());
			}
		}
		return _stack2.Pop();
	}

	/**
	* @brief Получение всех данных из очереди в виде массива.
	* @return Массив, содержащий все элементы очереди. Порядок элементов соответствует порядку добавления в очередь.
	*/
	T* GetData() const
	{
		size_t size1 = _stack1.GetSize();
		size_t size2 = _stack2.GetSize();
		size_t current = size1 + size2;

		T* data = new T[current];
		T* data1 = _stack1.GetData();
		T* data2 = _stack2.GetData();

		for (size_t i = 0; i < size2; ++i)
		{
			data[i] = data2[i];
		}
		for (size_t i = 0; i < size1; ++i)
		{
			data[size2 + i] = data1[i];
		}

		return data;
	}
};