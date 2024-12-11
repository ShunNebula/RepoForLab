#pragma once

/// <summary>
/// Структура ListItem представляет элемент двусвязного списка.
/// Хранит значение заданного типа и указатели на предыдущий и следующий элементы.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в элементе списка.</typeparam>
template <typename T>
struct ListItem
{
    /// <summary>
    /// Данные, хранящиеся в элементе списка.
    /// </summary>
    T data;

    /// <summary>
    /// Указатель на предыдущий элемент списка.
    /// </summary>
    ListItem<T>* prev;

    /// <summary>
    /// Указатель на следующий элемент списка.
    /// </summary>
    ListItem<T>* next;

    /// <summary>
    /// Конструктор элемента списка.
    /// </summary>
    /// <param name="value">Значение, которое будет храниться в элементе списка.</param>
    ListItem(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};