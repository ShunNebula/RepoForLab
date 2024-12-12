#pragma once

#include "RingBuffer.h"

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè î÷åðåäè íà îñíîâå êîëüöåâîãî áóôåðà.
* @tparam T Òèï äàííûõ, õðàíÿùèõñÿ â î÷åðåäè.
*/
template <typename T>
class QueueRingBuffer
{
private:
	/** @brief Êîëüöåâîé áóôåð, èñïîëüçóåìûé äëÿ ðåàëèçàöèè î÷åðåäè. */
	RingBuffer<T> _buffer;

	/** @brief Òåêóùèé ðàçìåð î÷åðåäè. */
	size_t _size;

public:
	/**
	* @brief Êîíñòðóêòîð î÷åðåäè.
	* @param capacity Åìêîñòü êîëüöåâîãî áóôåðà.
	*/
	QueueRingBuffer(size_t capacity) : _buffer(capacity), _size(0) {}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó î÷åðåäè.
	* @return true, åñëè î÷åðåäü ïóñòà; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsEmpty() const { return _buffer.IsEmpty(); }

	/**
	* @brief Ïðîâåðêà íà çàïîëíåííîñòü î÷åðåäè.
	* @return true, åñëè î÷åðåäü çàïîëíåíà; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsFull() const { return _buffer.IsFull(); }

	/**
	* @brief Âîçâðàùàåò ðàçìåð î÷åðåäè.
	* @return Ðàçìåð î÷åðåäè.
	*/
	size_t GetSize() const
	{
		return _size;
	}

	// TODO: RSDN
	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â î÷åðåäü.
	* @param data Ýëåìåíò, êîòîðûé íóæíî äîáàâèòü.
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

	// TODO: RSDN
	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç î÷åðåäè.
	* @return Ýëåìåíò, èçâëå÷åííûé èç î÷åðåäè.
	* @throw std::runtime_error Åñëè î÷åðåäü ïóñòà.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Î÷åðåäü ïóñòà!");
		}
		_size--;
		return _buffer.Pop();
	}

	/**
	* @brief Âîçâðàùàåò âñå äàííûå î÷åðåäè â âèäå ìàññèâà.
	* @return Ìàññèâ, ñîäåðæàùèé äàííûå î÷åðåäè.
	*/
	T* GetData() const
	{
		return _buffer.GetData();
	}
};