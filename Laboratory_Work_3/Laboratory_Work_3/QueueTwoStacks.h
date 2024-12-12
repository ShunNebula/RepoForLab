#pragma once

#include "stack.h"

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè î÷åðåäè ñ èñïîëüçîâàíèåì äâóõ ñòåêîâ.
* @tparam T Òèï äàííûõ, õðàíÿùèõñÿ â î÷åðåäè.
*/
template <typename T>
class QueueTwoStacks
{
private:
	/** @brief Ïåðâûé ñòåê, èñïîëüçóåìûé äëÿ äîáàâëåíèÿ ýëåìåíòîâ. */
	Stack<T> _stack1;

	/** @brief Âòîðîé ñòåê, èñïîëüçóåìûé äëÿ èçâëå÷åíèÿ ýëåìåíòîâ. */
	Stack<T> _stack2;

public:
	/**
	* @brief Ïðîâåðêà íà ïóñòîòó î÷åðåäè.
	* @return true, åñëè î÷åðåäü ïóñòà; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsEmpty() && _stack2.IsEmpty();
	}

	/**
	* @brief Âîçâðàùàåò ðàçìåð î÷åðåäè.
	* @return Ðàçìåð î÷åðåäè.
	*/
	size_t GetSize() const
	{
		return _stack1.GetSize() + _stack2.GetSize();
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â î÷åðåäü.
	* @param data Ýëåìåíò, êîòîðûé íóæíî äîáàâèòü.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	// TODO: RSDN
	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç î÷åðåäè.
	* @return Ýëåìåíò, èçâëå÷åííûé èç î÷åðåäè.
	* @throw std::underflow_error Åñëè î÷åðåäü ïóñòà.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Î÷åðåäü ïóñòà!");
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

	// TODO: RSDN
	/**
	* @brief Ïîëó÷åíèå âñåõ äàííûõ èç î÷åðåäè â âèäå ìàññèâà.
	* @return Ìàññèâ, ñîäåðæàùèé âñå ýëåìåíòû î÷åðåäè. Ïîðÿäîê ýëåìåíòîâ ñîîòâåòñòâóåò ïîðÿäêó äîáàâëåíèÿ â î÷åðåäü.
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