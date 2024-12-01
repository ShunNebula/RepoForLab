#pragma once

#include <vector>
#include <stdexcept>

/**
* @brief ��������� ����� ��� ���������� �����.
* @tparam T ��� ������, ���������� � �����.
*/
template <typename T>
class Stack
{
private:
	/**
	* @brief ��������� ���� �����.
	*/
	struct Node
	{
		/** @brief ������, ���������� � ����. */
		T data;

		/** @brief ��������� �� ��������� ����. */
		Node* next;

		/**
		* @brief ����������� ����.
		* @param data ������ ��� �������� � ����.
		*/
		Node(const T& data) : data(data), next(nullptr) {}
	};

	/** @brief ��������� �� ������� �����. */
	Node* _top;

public:
	/**
	* @brief ����������� �����.
	* ������� ������ ����.
	*/
	Stack() : _top(nullptr) {}

	/**
	* @brief ���������� �����.
	* ����������� ������, ���������� ������.
	*/
	~Stack()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	/**
	* @brief �������� �� ������� �����.
	* @return true, ���� ���� ����; false � ��������� ������.
	*/
	bool IsEmpty() const
	{
		return _top == nullptr;
	}

	/**
	* @brief ���������� �������� � ����.
	* @param data �������, ������� ����� ��������.
	*/
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
	}

	/**
	* @brief ���������� �������� �� �����.
	* @return ������� ������� �����.
	* @throw std::underflow_error ���� ���� ����.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("���� ����!");
		}
		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		return data;
	}

	/**
	* @brief ���������� ������ ����� � ���� �������.
	* @return ������, ���������� ������ �����.
	*/
	std::vector<T> GetData() const
	{
		std::vector<T> data;
		Node* current = _top;
		while (current != nullptr)
		{
			data.push_back(current->data);
			current = current->next;
		}
		return data;
	}
};