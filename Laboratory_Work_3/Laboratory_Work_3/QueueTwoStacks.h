#pragma once

#include "stack.h"

/**
* @brief ��������� ����� ��� ���������� ������� � �������������� ���� ������.
* @tparam T ��� ������, ���������� � �������.
*/
template <typename T>
class QueueTwoStacks
{
private:
	/** @brief ������ ����, ������������ ��� ���������� ���������. */
	Stack<T> _stack1;

	/** @brief ������ ����, ������������ ��� ���������� ���������. */
	Stack<T> _stack2;

public:
	/**
	* @brief �������� �� ������� �������.
	* @return true, ���� ������� �����; false � ��������� ������.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsEmpty() && _stack2.IsEmpty();
	}

	/**
	* @brief ���������� ������ �������.
	* @return ������ �������.
	*/
	size_t GetSize() const
	{
		return _stack1.GetSize() + _stack2.GetSize();
	}

	/**
	* @brief ���������� �������� � �������.
	* @param data �������, ������� ����� ��������.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	/**
	* @brief ���������� �������� �� �������.
	* @return �������, ����������� �� �������.
	* @throw std::underflow_error ���� ������� �����.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("������� �����!");
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
	* @brief ��������� ���� ������ �� ������� � ���� �������.
	* @return ������, ���������� ��� �������� �������. ������� ��������� ������������� ������� ���������� � �������.
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