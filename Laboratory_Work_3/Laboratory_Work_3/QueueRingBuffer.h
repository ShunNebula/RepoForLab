#pragma once

#include "RingBuffer.h"

/**
* @brief ��������� ����� ��� ���������� ������� �� ������ ���������� ������.
* @tparam T ��� ������, ���������� � �������.
*/
template <typename T>
class QueueRingBuffer
{
private:
	/** @brief ��������� �����, ������������ ��� ���������� �������. */
	RingBuffer<T> _buffer;

	/** @brief ������� ������ �������. */
	size_t _size;

public:
	/**
	* @brief ����������� �������.
	* @param capacity ������� ���������� ������.
	*/
	QueueRingBuffer(size_t capacity) : _buffer(capacity), _size(0) {}

	/**
	* @brief �������� �� ������� �������.
	* @return true, ���� ������� �����; false � ��������� ������.
	*/
	bool IsEmpty() const { return _buffer.IsEmpty(); }

	/**
	* @brief �������� �� ������������� �������.
	* @return true, ���� ������� ���������; false � ��������� ������.
	*/
	bool IsFull() const { return _buffer.IsFull(); }

	/**
	* @brief ���������� ������ �������.
	* @return ������ �������.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief ���������� �������� � �������.
	* @param data �������, ������� ����� ��������.
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
	* @brief ���������� �������� �� �������.
	* @return �������, ����������� �� �������.
	* @throw std::runtime_error ���� ������� �����.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("������� �����!");
		}
		_size--;
		return _buffer.Pop();
	}

	/**
	* @brief ���������� ��� ������ ������� � ���� �������.
	* @return ������, ���������� ������ �������.
	*/
	T* GetData() const
	{
		return _buffer.GetData();
	}
};