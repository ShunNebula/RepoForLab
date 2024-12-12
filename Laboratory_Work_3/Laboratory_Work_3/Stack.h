#pragma once

#include <vector>
#include <stdexcept>

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè ñòåêà.
* @tparam T Òèï äàííûõ, õðàíÿùèõñÿ â ñòåêå.
*/
template <typename T>
class Stack
{
private:
	/**
	* @brief Ñòðóêòóðà óçëà ñòåêà.
	*/
	struct Node
	{
		/** @brief Äàííûå, õðàíÿùèåñÿ â óçëå. */
		T data;

		/** @brief Óêàçàòåëü íà ñëåäóþùèé óçåë. */
		Node* next;

		/**
		* @brief Êîíñòðóêòîð óçëà.
		* @param data Äàííûå äëÿ õðàíåíèÿ â óçëå.
		*/
		Node(const T& data) : data(data), next(nullptr) {}
	};

	/** @brief Óêàçàòåëü íà âåðøèíó ñòåêà. */
	Node* _top;

	/** Òåêóùèé ðàìåð ñòåêà. */
	size_t _size;

public:
	/**
	* @brief Êîíñòðóêòîð ñòåêà.
	* Ñîçäàåò ïóñòîé ñòåê.
	*/
	Stack() : _top(nullptr), _size(0) {}

	/**
	* @brief Äåñòðóêòîð ñòåêà.
	* Îñâîáîæäàåò ïàìÿòü, çàíèìàåìóþ ñòåêîì.
	*/
	~Stack()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	/**
	* @brief Âîçâðàùàåò ðàçìåð ñòåêà.
	* @return Ðàçìåð ñòåêà.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó ñòåêà.
	* @return true, åñëè ñòåê ïóñò; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsEmpty() const
	{
		return _top == nullptr;
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â ñòåê.
	* @param data Ýëåìåíò, êîòîðûé íóæíî äîáàâèòü.
	*/
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
		_size++;
	}

	// TODO: RSDN
	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç ñòåêà.
	* @return Âåðõíèé ýëåìåíò ñòåêà.
	* @throw std::underflow_error Åñëè ñòåê ïóñò.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Ñòåê ïóñò!");
		}
		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		_size--;
		return data;
	}

	// TODO: RSDN
	/**
	* @brief Âîçâðàùàåò äàííûå ñòåêà â âèäå ìàññèâà.
	* @return Ìàññèâ, ñîäåðæàùèé äàííûå ñòåêà.
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