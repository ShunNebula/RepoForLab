#pragma once

#include "ListItem.h"
#include <chrono>
#include <iostream>
#include <algorithm>

/// <summary>
/// Класс List реализует двусвязный список.
/// Поддерживает добавление, удаление, вставку, сортировку и поиск элементов.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в списке.</typeparam>
template <typename T>
class List
{
private:
    /// <summary>
    /// Указатель на первый элемент списка.
    /// </summary>
    ListItem<T>* head;

    /// <summary>
    /// Указатель на последний элемент списка.
    /// </summary>
    ListItem<T>* tail;

    /// <summary>
    /// Размер списка.
    /// </summary>
    size_t size;

public:
    /// <summary>
    /// Конструктор списка.
    /// </summary>
    List() : head(nullptr), tail(nullptr), size(0) {}

    /// <summary>
    /// Деструктор списка.
    /// </summary>
    ~List()
    {
        Clear();
    }

    /// <summary>
    /// Возвращает размер списка.
    /// </summary>
    /// <returns>Размер списка.</returns>
    size_t GetSize() const
    {
        return size;
    }

    /// <summary>
    /// Добавляет элемент в список.
    /// </summary>
    /// <param name="value">Значение, добавляемое в список.</param>
    /// <param name="atStart">Флаг, указывающий, добавлять ли элемент в начало (true) или в конец (false).</param>
    void Add(const T& value, bool atStart = true)
    {
        ListItem<T>* newNode = new ListItem<T>(value);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else if (atStart)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }


    /// <summary>
    /// Вставляет элемент в список.
    /// </summary>
    /// <param name="node">Узел, после/перед которым нужно вставить новый элемент.</param>
    /// <param name="value">Значение, добавляемое в список.</param>
    /// <param name="after">Флаг, указывающий, вставлять ли элемент после (true) или перед (false) заданным узлом.</param>
    void Insert(ListItem<T>* node, const T& value, bool after = true)
    {
        if (!node)
        {
            Add(value, !after); // if node is null, add to the opposite end
            return;
        }

        if (node == (after ? tail : head))
        {
            Add(value, !after); // add to the opposite end if at the boundary
            return;
        }

        ListItem<T>* newNode = new ListItem<T>(value);
        if (after)
        {
            newNode->next = node->next;
            newNode->prev = node;
            node->next->prev = newNode;
            node->next = newNode;
        }
        else
        {
            newNode->prev = node->prev;
            newNode->next = node;
            node->prev->next = newNode;
            node->prev = newNode;
        }
        size++;
    }

    /// <summary>
    /// Удаляет заданный узел из списка.
    /// </summary>
    /// <param name="node">Узел для удаления.</param>
    void Remove(ListItem<T>* node)
    {
        if (!node) return;

        if (node == head)
        {
            head = node->next;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        else if (node == tail)
        {
            tail = node->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }

    /// <summary>
    /// Сортирует список по возрастанию значений данных.
    /// </summary>
    void Sort()
    {
        if (size <= 1) return;

        bool swapped;
        ListItem<T>* ptr1;
        ListItem<T>* lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    std::swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }


    /// <summary>
    /// Выполняет линейный поиск элемента в списке.
    /// </summary>
    /// <param name="value">Значение для поиска.</param>
    /// <returns>Указатель на найденный элемент, или nullptr, если элемент не найден.</returns>
    ListItem<T>* LinearSearch(const T& value)
    {
        ListItem<T>* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }


    /// <summary>
    /// Очищает список.
    /// </summary>
    void Clear()
    {
        ListItem<T>* current = head;
        while (current != nullptr)
        {
            ListItem<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    /// <summary>
    /// Заполняет список значениями для бенчмарка.
    /// </summary>
    /// <param name="size">Количество элементов для добавления.</param>
    void FillBenchmark(int size) {
        for (int i = 0; i < size; i++)
        {
            Add(i, false);
        }
    }



    /// <summary>
    /// Измеряет время выполнения операции.
    /// </summary>
    /// <param name="operation">Функтор, представляющий операцию для измерения.</param>
    /// <param name="size">Размер данных для операции (передается в operation).</param>
    /// <param name="operationName">Название операции для вывода.</param>
    /// <returns>Время выполнения операции в секундах.</returns>
    template<typename F>
    double Benchmark(F operation, int size, const std::string& operationName)
    {
        auto start = std::chrono::steady_clock::now();
        operation(size);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        return elapsed.count();
    }


    /// <summary>
    /// Бенчмарк для добавления элементов.
    /// </summary>
    /// <param name="size">Количество элементов для добавления.</param>
    /// <param name="atStart">Флаг, указывающий, добавлять ли элементы в начало (true) или в конец (false).</param>
    auto AddBenchmark(int size, bool atStart)
    {
        return [this, atStart](int size) {
            for (int i = 0; i < size; ++i)
            {
                Add(i, atStart);
            }
            };
    }

    /// <summary>
    /// Бенчмарк для удаления элементов.
    /// </summary>
    /// <param name="size">Количество элементов для удаления.</param>
    auto RemoveBenchmark(int size)
    {
        return [this](int size)
            {
                for (int i = 0; i < size; i++)
                {
                    Remove(LinearSearch(i));
                }
            };
    }

    /// <summary>
    /// Бенчмарк для вставки элементов.
    /// </summary>
    /// <param name="node">Узел, после/перед которым нужно вставить новый элемент. Если nullptr, вставка в начало/конец.</param>
    /// <param name="size">Количество элементов для вставки.</param>
    /// <param name="after">Флаг, указывающий, вставлять ли элемент после (true) или перед (false) заданным узлом.</param>
    auto InsertBenchmark(ListItem<T>* node, int size, bool after) {
        return[this, node, after](int size) {
            for (int i = 0; i < size; i++)
            {
                Insert(node, i, after);
            }
            };
    }


    /// <summary>
    /// Возвращает указатель на головной элемент списка.
    /// </summary>
    /// <returns>Указатель на головной элемент списка.</returns>
    ListItem<T>* GetHead() const {
        return head;
    }
};