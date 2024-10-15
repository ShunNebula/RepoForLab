#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Конструктор по умолчанию.
DynamicArray::DynamicArray() : _size(0), _capacity(4), _array(new int[_capacity]) {}

// Конструктор с заданным начальным размером.
DynamicArray::DynamicArray(int initialCapacity) : _size(0), _capacity(initialCapacity), _array(new int[_capacity]) {}

// Деструктор.
DynamicArray::~DynamicArray() {
    delete[] _array;
}

// Возвращает размер массива.
int DynamicArray::GetSize() {
    return _size;
}

// Возвращает вместимость массива.
int DynamicArray::GetCapacity() {
    return _capacity;
}

// Возвращает массив.
int* DynamicArray::GetArray() {
    return _array;
}

// Вспомогательная функция для расширения массива.
void DynamicArray::_resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

// Добавляет элемент в массив.
void DynamicArray::AddElement(int index, int value) {
    if (index < 0 || index > _size) {
        cerr << "Invalid index." << endl;
        return;
    }

    if (_size == _capacity) {
        _resize(_capacity * _growthFactor);
    }

    for (int i = _size; i > index; i--) {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
    _size++;
}

// Удаляет элемент массива по передаваемому индексу.
void DynamicArray::RemoveByIndex(int index) {
    if (index < 0 || index >= _size) {
        cerr << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < _size - 1; i++) {
        _array[i] = _array[i + 1];
    }
    _size--;

    // Проверка условия для уменьшения размера массива
    if (_capacity / _size >= _growthFactor) {
        _resize(_capacity / _growthFactor);
    }
}

// Удаляет значение элемента по его передаваемому значению.
void DynamicArray::RemoveByValue(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            RemoveByIndex(i);
            return;
        }
    }
    cerr << "Value not found in array." << endl;
}

// Возвращает элемент по индексу.
int DynamicArray::GetElement(int index) {
    if (index < 0 || index >= _size) {
        cerr << "Invalid index." << endl;
        return -1;
    }
    return _array[index];
}

// Сортирует массив методом Shaker Sort.
void DynamicArray::SortArray() {
    int left = 0;
    int right = _size - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (_array[i] > _array[i + 1]) {
                swap(_array[i], _array[i + 1]);
                swapped = true;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (_array[i] < _array[i - 1]) {
                swap(_array[i], _array[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}

// Сортирует массив методом Comb Sort.
//void DynamicArray::SortArray() {
//    int gap = _size;
//    bool swapped = true;
//
//    while (gap > 1 || swapped) {
//        gap = (gap * 10) / 13; // Вычисление нового значения промежутка
//        if (gap < 1) {
//            gap = 1;
//        }
//
//        swapped = false;
//        for (int i = 0; i < _size - gap; i++) {
//            if (_array[i] > _array[i + gap]) {
//                std::swap(_array[i], _array[i + gap]);
//                swapped = true;
//            }
//        }
//    }
//}


// Линейный поиск индекса элемента по передаваемому значению.
void DynamicArray::LinerSearch(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            cout << "Element index: " << i << endl;
            return;
        }
    }
    cout << "The element was not found in the array." << endl;
}

// Бинарный поиск индекса элемента по передаваемому значению.
void DynamicArray::BinarySearch(int value) {
    int left = 0;
    int right = _size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (_array[middle] == value) {
            cout << "Element index: " << middle << endl;
            return;
        }
        else if (_array[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    cout << "The element was not found in the array." << endl;
}
