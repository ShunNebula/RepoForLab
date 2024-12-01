#pragma once

#include "stack.h"

/**
* @brief ��������� ����� ��� ���������� ������� � �������������� ���� ������.
*
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
	* @return ������, ���������� ��� �������� �������.  ������� ��������� ������������� ������� ���������� � �������.
	*/
	std::vector<T> GetData() const
	{
		std::vector<T> data;

		std::vector<T> data1 = _stack1.GetData();
		std::reverse(data1.begin(), data1.end());

		std::vector<T> data2 = _stack2.GetData();

		data.insert(data.end(), data1.begin(), data1.end());
		data.insert(data.end(), data2.begin(), data2.end());
		return data;
	}
};