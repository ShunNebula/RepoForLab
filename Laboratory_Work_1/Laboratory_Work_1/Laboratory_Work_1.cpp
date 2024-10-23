#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main() {
    DynamicArray array;

    // Инициализация массива.
    array.AddElement(0, 12);
    array.AddElement(1, 3);
    array.AddElement(2, 8);
    array.AddElement(3, 25);

    // Вывод меню.
    while (true) {
        cout << endl << "Laboratory Work #1 - Dynamic Array" << endl;
        cout << "Current array: ";
        for (int i = 0; i < array.GetSize(); i++) {
            cout << array.GetElement(i) << ", ";
        }
        cout << endl << "Select the action you want to do:" << endl;
        cout << "1. Remove an element by index from an array" << endl;
        cout << "2. Remove an element by value from an array" << endl;
        cout << "3. Insert an element at the beginning" << endl;
        cout << "4. Insert an element at the end" << endl;
        cout << "5. Insert after a certain element" << endl;
        cout << "6. Sort array" << endl;
        cout << "7. Linear search for an element in an array" << endl;
        cout << "8. Binary search for an element in an array" << endl;
        cout << "0. Exit" << endl;
        cout << "Your input: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int index;
                cout << "Enter the index of the item to be deleted: ";
                cin >> index;
                if (index < 0 || index >= array.GetSize()) {
                    cout << "Invalid index." << endl;
                }
                else {
                    array.RemoveByIndex(index);
                }
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value of the element to delete: ";
                cin >> value;
                array.RemoveByValue(value);
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value of the element to insert at the beginning: ";
                cin >> value;
                array.AddElement(0, value);
                break;
            }
            case 4: {
                int value;
                cout << "Enter the value of the element to insert at the end: ";
                cin >> value;
                array.AddElement(array.GetSize(), value);
                break;
            }
            case 5: {
                int value, index;
                cout << "Enter the value of the element to insert: ";
                cin >> value;
                cout << "Enter the index of the element after which you want to insert: ";
                cin >> index;
                if (index < 0 || index >= array.GetSize()) {
                    cout << "Invalid index." << endl;
                }
                else {
                    array.AddElement(index + 1, value);
                }
                break;
            }
            case 6:
                array.SortArray();
                break;
            case 7: {
                int value;
                cout << "Enter the value of the element to search: ";
                cin >> value;
                array.LinerSearch(value);
                break;
            }
            case 8: {
                int value;
                cout << "Enter the value of the element to search:";
                cin >> value;
                array.BinarySearch(value);
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Unknown command. Please re-enter." << endl;
            }
    }

    return 0;
}
