#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

/**
* @brief Шаблонный класс для реализации динамического кольцевого буфера.
* @tparam T Тип данных, хранящихся в буфере.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief Указатель на динамически выделенный массив для хранения данных. */
	T* _buffer = new T();

	/** @brief Индекс головного элемента. */
	size_t _head;

	/** @brief Индекс хвостового элемента. */
	size_t _tail;

	/** @brief Текущий размер буфера. */
	size_t _size;

	/** @brief Текущая емкость буфера. */
	size_t _capacity;

public:
	/**
	* @brief Конструктор кольцевого буфера.
	* @param capacity Начальная емкость буфера.
	* @throw std::invalid_argument Если capacity равно нулю или меньше.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("capacity должно быть больше нуля");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief Деструктор кольцевого буфера.
	* Освобождает динамически выделенную память.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief Возвращает размер кольцевого буфера.
	* @return Размер кольцевого буфера.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief Увеличивает объём кольцевого буфера.
	*/
	void Resize()
	{
		_capacity *= 2;
	}

	/**
	* @brief Проверка на пустоту буфера.
	* @return true, если буфер пуст; false в противном случае.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief Проверка на заполненность буфера.
	* @return true, если буфер полон; false в противном случае.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief Возвращает количество свободного места в буфере.
	* @return Количество свободных ячеек.
	*/
	size_t FreeSpace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief Возвращает количество занятых ячеек в буфере.
	* @return Количество занятых ячеек.
	*/
	size_t UsedSpace() const
	{
		return _size;
	}

	/**
	* @brief Добавление элемента в буфер.
	* @param data Элемент для добавления.
	* @throw std::overflow_error Если буфер полон.
	*/
	void Push(const T& data)
	{
		_buffer[_tail] = data;
		_tail = (_tail + 1) % _capacity;
		if (IsFull())
		{
			_head = (_head + 1) % _capacity;
		}
		else
		{
			_size++;
		}
	}

	/**
	* @brief Извлечение элемента из буфера.
	* @return Извлеченный элемент.
	* @throw std::underflow_error Если буфер пуст.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Буфер пуст!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	/**
	* @brief Возвращает данные буфера в виде массива.
	* @return Массив, содержащий данные буфера.
	*/
	T* GetData() const
	{
		if (IsEmpty())
		{
			return nullptr;
		}

		T* data = new T[_size];
		size_t current = _head;
		for (size_t i = 0; i < _size; ++i)
		{
			data[i] = _buffer[current];
			current = (current + 1) % _capacity;
		}
		return data;
	}
};