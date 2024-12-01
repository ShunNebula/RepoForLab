#pragma once

#include <vector>
#include <stdexcept>

/**
* @brief Шаблонный класс для реализации стека.
* @tparam T Тип данных, хранящихся в стеке.
*/
template <typename T>
class Stack
{
private:
	/**
	* @brief Структура узла стека.
	*/
	struct Node
	{
		/** @brief Данные, хранящиеся в узле. */
		T data;

		/** @brief Указатель на следующий узел. */
		Node* next;

		/**
		* @brief Конструктор узла.
		* @param data Данные для хранения в узле.
		*/
		Node(const T& data) : data(data), next(nullptr) {}
	};

	/** @brief Указатель на вершину стека. */
	Node* _top;

public:
	/**
	* @brief Конструктор стека.
	* Создает пустой стек.
	*/
	Stack() : _top(nullptr) {}

	/**
	* @brief Деструктор стека.
	* Освобождает память, занимаемую стеком.
	*/
	~Stack()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	/**
	* @brief Проверка на пустоту стека.
	* @return true, если стек пуст; false в противном случае.
	*/
	bool IsEmpty() const
	{
		return _top == nullptr;
	}

	/**
	* @brief Добавление элемента в стек.
	* @param data Элемент, который нужно добавить.
	*/
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
	}

	/**
	* @brief Извлечение элемента из стека.
	* @return Верхний элемент стека.
	* @throw std::underflow_error Если стек пуст.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Стек пуст!");
		}
		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		return data;
	}

	/**
	* @brief Возвращает данные стека в виде вектора.
	* @return Вектор, содержащий данные стека.
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