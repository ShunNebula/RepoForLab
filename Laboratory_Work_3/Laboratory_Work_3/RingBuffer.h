#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè äèíàìè÷åñêîãî êîëüöåâîãî áóôåðà.
* @tparam T Òèï äàííûõ, õðàíÿùèõñÿ â áóôåðå.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief Óêàçàòåëü íà äèíàìè÷åñêè âûäåëåííûé ìàññèâ äëÿ õðàíåíèÿ äàííûõ. */
	T* _buffer = new T();

	/** @brief Èíäåêñ ãîëîâíîãî ýëåìåíòà. */
	size_t _head;

	/** @brief Èíäåêñ õâîñòîâîãî ýëåìåíòà. */
	size_t _tail;

	/** @brief Òåêóùèé ðàçìåð áóôåðà. */
	size_t _size;

	/** @brief Òåêóùàÿ åìêîñòü áóôåðà. */
	size_t _capacity;

public:
	// TODO: RSDN
	/**
	* @brief Êîíñòðóêòîð êîëüöåâîãî áóôåðà.
	* @param capacity Íà÷àëüíàÿ åìêîñòü áóôåðà.
	* @throw std::invalid_argument Åñëè capacity ðàâíî íóëþ èëè ìåíüøå.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("capacity äîëæíî áûòü áîëüøå íóëÿ");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief Äåñòðóêòîð êîëüöåâîãî áóôåðà.
	* Îñâîáîæäàåò äèíàìè÷åñêè âûäåëåííóþ ïàìÿòü.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief Âîçâðàùàåò ðàçìåð êîëüöåâîãî áóôåðà.
	* @return Ðàçìåð êîëüöåâîãî áóôåðà.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	/**
	* @brief Óâåëè÷èâàåò îáú¸ì êîëüöåâîãî áóôåðà.
	*/
	void Resize()
	{
		_capacity *= 2;
	}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó áóôåðà.
	* @return true, åñëè áóôåð ïóñò; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief Ïðîâåðêà íà çàïîëíåííîñòü áóôåðà.
	* @return true, åñëè áóôåð ïîëîí; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief Âîçâðàùàåò êîëè÷åñòâî ñâîáîäíîãî ìåñòà â áóôåðå.
	* @return Êîëè÷åñòâî ñâîáîäíûõ ÿ÷ååê.
	*/
	size_t FreeSpace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief Âîçâðàùàåò êîëè÷åñòâî çàíÿòûõ ÿ÷ååê â áóôåðå.
	* @return Êîëè÷åñòâî çàíÿòûõ ÿ÷ååê.
	*/
	size_t UsedSpace() const
	{
		return _size;
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â áóôåð.
	* @param data Ýëåìåíò äëÿ äîáàâëåíèÿ.
	* @throw std::overflow_error Åñëè áóôåð ïîëîí.
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

	// TODO: RSDN
	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç áóôåðà.
	* @return Èçâëå÷åííûé ýëåìåíò.
	* @throw std::underflow_error Åñëè áóôåð ïóñò.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Áóôåð ïóñò!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	// TODO: RSDN
	/**
	* @brief Âîçâðàùàåò äàííûå áóôåðà â âèäå ìàññèâà.
	* @return Ìàññèâ, ñîäåðæàùèé äàííûå áóôåðà.
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