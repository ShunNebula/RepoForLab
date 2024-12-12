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

	/** ������� ����� �����. */
	size_t _size;

public:
	/**
	* @brief ����������� �����.
	* ������� ������ ����.
	*/
	Stack() : _top(nullptr), _size(0) {}

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
	* @brief ���������� ������ �����.
	* @return ������ �����.
	*/
	size_t GetSize() const
	{
		return _size;
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
		_size++;
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
		_size--;
		return data;
	}

	/**
	* @brief ���������� ������ ����� � ���� �������.
	* @return ������, ���������� ������ �����.
	*/
	T* GetData() const
	{
		if (IsEmpty())
		{
			return nullptr;
		}

		T* data = new T[_size];
		Node* current = _top;
		for (size_t i = 0; i < _size; ++i)
		{
			data[i] = current->data;
			current = current->next;
		}
		return data;
	}
};