#pragma once

#include "RingBuffer.h"

/**
* @brief Шаблонный класс для реализации очереди на основе кольцевого буфера.
* @tparam T Тип данных, хранящихся в очереди.
*/
template <typename T>
class QueueRingBuffer
{
private:
	/** @brief Кольцевой буфер, используемый для реализации очереди. */
	RingBuffer<T> _buffer;

	/** @brief Текущий размер очереди. */
	size_t _size;

public:
	/**
	* @brief Конструктор очереди.
	* @param capacity Емкость кольцевого буфера.
	*/
	QueueRingBuffer(size_t capacity) : _buffer(capacity), _size(0) {}

	/**
	* @brief Проверка на пустоту очереди.
	* @return true, если очередь пуста; false в противном случае.
	*/
	bool IsEmpty() const { return _buffer.IsEmpty(); }

	/**
	* @brief Проверка на заполненность очереди.
	* @return true, если очередь заполнена; false в противном случае.
	*/
	bool IsFull() const { return _buffer.IsFull(); }

	/**
	* @brief Возвращает размер очереди.
	* @return Размер очереди.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief Добавление элемента в очередь.
	* @param data Элемент, который нужно добавить.
	*/
	void Enqueue(const T& data)
	{
		if (_buffer.FreeSpace() == 1)
		{
			_buffer.Resize();
		}
		_buffer.Push(data);
		_size++;
	}

	/**
	* @brief Извлечение элемента из очереди.
	* @return Элемент, извлеченный из очереди.
	* @throw std::runtime_error Если очередь пуста.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Очередь пуста!");
		}
		_size--;
		return _buffer.Pop();
	}

	/**
	* @brief Возвращает все данные очереди в виде массива.
	* @return Массив, содержащий данные очереди.
	*/
	T* GetData() const
	{
		return _buffer.GetData();
	}
};