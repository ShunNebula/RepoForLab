#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

/**
* @brief ��������� ����� ��� ���������� ������������� ���������� ������.
* @tparam T ��� ������, ���������� � ������.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief ��������� �� ����������� ���������� ������ ��� �������� ������. */
	T* _buffer = new T();

	/** @brief ������ ��������� ��������. */
	size_t _head;

	/** @brief ������ ���������� ��������. */
	size_t _tail;

	/** @brief ������� ������ ������. */
	size_t _size;

	/** @brief ������� ������� ������. */
	size_t _capacity;

public:
	/**
	* @brief ����������� ���������� ������.
	* @param capacity ��������� ������� ������.
	* @throw std::invalid_argument ���� capacity ����� ���� ��� ������.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("capacity ������ ���� ������ ����");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief ���������� ���������� ������.
	* ����������� ����������� ���������� ������.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief ���������� ������ ���������� ������.
	* @return ������ ���������� ������.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief ����������� ����� ���������� ������.
	*/
	void Resize()
	{
		_capacity *= 2;
	}

	/**
	* @brief �������� �� ������� ������.
	* @return true, ���� ����� ����; false � ��������� ������.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief �������� �� ������������� ������.
	* @return true, ���� ����� �����; false � ��������� ������.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief ���������� ���������� ���������� ����� � ������.
	* @return ���������� ��������� �����.
	*/
	size_t FreeSpace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief ���������� ���������� ������� ����� � ������.
	* @return ���������� ������� �����.
	*/
	size_t UsedSpace() const
	{
		return _size;
	}

	/**
	* @brief ���������� �������� � �����.
	* @param data ������� ��� ����������.
	* @throw std::overflow_error ���� ����� �����.
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
	* @brief ���������� �������� �� ������.
	* @return ����������� �������.
	* @throw std::underflow_error ���� ����� ����.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("����� ����!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	/**
	* @brief ���������� ������ ������ � ���� �������.
	* @return ������, ���������� ������ ������.
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