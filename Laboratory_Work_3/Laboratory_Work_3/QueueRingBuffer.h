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

public:
	/**
	* @brief ����������� �������.
	* @param capacity ������� ���������� ������.
	*/
	explicit QueueRingBuffer(size_t capacity) : _buffer(capacity) {}

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
	* @brief ���������� �������� � �������.
	* @param data �������, ������� ����� ��������.
	*/
	void Enqueue(const T& data)
	{
		_buffer.Push(data);
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
		return _buffer.Pop();
	}

	/**
	* @brief ���������� ��� ������ ������� � ���� �������.
	* @return ������, ���������� ������ �������.
	*/
	std::vector<T> GetData() const
	{
		return _buffer.GetData();
	}
};