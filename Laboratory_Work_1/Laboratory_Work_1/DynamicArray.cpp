#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

// ����������� �� ���������.
DynamicArray::DynamicArray() : _size(0), _capacity(4), _array(new int[_capacity]) {}

// ����������� � �������� ��������� ��������.
DynamicArray::DynamicArray(int initialCapacity) : _size(0), _capacity(initialCapacity), _array(new int[_capacity]) {}

// ����������.
DynamicArray::~DynamicArray() {
    delete[] _array;
}

// ���������� ������ �������.
int DynamicArray::GetSize() {
    return _size;
}

// ���������� ����������� �������.
int DynamicArray::GetCapacity() {
    return _capacity;
}

// ���������� ������.
int* DynamicArray::GetArray() {
    return _array;
}

// ��������������� ������� ��� ���������� �������.
void DynamicArray::_resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; i++) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

// ��������� ������� � ������.
void DynamicArray::AddElement(int index, int value) {
    if (index < 0 || index > _size) {
        std::cerr << "Invalid index." << std::endl;
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

// ������� ������� ������� �� ������������� �������.
void DynamicArray::RemoveByIndex(int index) {
    if (index < 0 || index >= _size) {
        std::cerr << "Invalid index." << std::endl;
        return;
    }

    for (int i = index; i < _size - 1; i++) {
        _array[i] = _array[i + 1];
    }
    _size--;

    // �������� ������� ��� ���������� ������� �������
    if (_capacity / _size >= _growthFactor) {
        _resize(_capacity / _growthFactor);
    }
}

// ������� �������� �������� �� ��� ������������� ��������.
void DynamicArray::RemoveByValue(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            RemoveByIndex(i);
            return;
        }
    }
    std::cerr << "Value not found in array." << std::endl;
}

// ���������� ������� �� �������.
int DynamicArray::GetElement(int index) {
    if (index < 0 || index >= _size) {
        std::cerr << "Invalid index." << std::endl;
        return -1;
    }
    return _array[index];
}

// ��������� ������ ������� Shaker Sort.
void DynamicArray::SortArray() {
    int left = 0;
    int right = _size - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        // ������ ����� �������
        for (int i = left; i < right; i++) {
            if (_array[i] > _array[i + 1]) {
                std::swap(_array[i], _array[i + 1]);
                swapped = true;
            }
        }
        right--;

        // ������ ������ ������
        for (int i = right; i > left; i--) {
            if (_array[i] < _array[i - 1]) {
                std::swap(_array[i], _array[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}

// �������� ����� ������� �������� �� ������������� ��������.
void DynamicArray::LinerSearch(int value) {
    for (int i = 0; i < _size; i++) {
        if (_array[i] == value) {
            std::cout << "Element index: " << i << std::endl;
            return;
        }
    }
    std::cout << "The element was not found in the array." << std::endl;
}

// �������� ����� ������� �������� �� ������������� ��������.
void DynamicArray::BinarySearch(int value) {
    int left = 0;
    int right = _size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (_array[middle] == value) {
            std::cout << "Element index: " << middle << std::endl;
            return;
        }
        else if (_array[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    std::cout << "The element was not found in the array." << std::endl;
}
