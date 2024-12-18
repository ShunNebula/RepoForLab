#include "BinaryTree.h"
#include <iostream>

void PrintMenu() 
{
    std::cout << "\nMenu:\n";
    std::cout << "1. Insert element\n";
    std::cout << "2. Remove element\n";
    std::cout << "3. Find element\n";
    std::cout << "4. Find minimum\n";
    std::cout << "5. Find maximum\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void PrintTreeBrackets(BinaryTreeNode* node) 
{
    if (node == nullptr) 
    {
        std::cout << "null";
        return;
    }

    std::cout << "(" << node->Data;
    std::cout << " ";
    PrintTreeBrackets(node->Left);
    std::cout << " ";
    PrintTreeBrackets(node->Right);
    std::cout << ")";
}

int main() 
{
    BinaryTree tree;
    int choice, value;

    do 
    {
        PrintTreeBrackets(tree.GetRoot());
        PrintMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            tree.Insert(value);
            break;
        case 2:
            std::cout << "Enter value to remove: ";
            std::cin >> value;
            tree.Remove(tree.GetRoot(), value);
            break;
        case 3:
            std::cout << "Enter value to find: ";
            std::cin >> value;
            if (tree.Find(tree.GetRoot(), value) != nullptr) 
            {
                std::cout << "Value found.\n";
            }
            else 
            {
                std::cout << "Value not found.\n";
            }
            break;
        case 4:
            if (BinaryTreeNode* minNode = tree.FindMin(tree.GetRoot())) 
            {
                std::cout << "Minimum value: " << minNode->Data << "\n";
            }
            else 
            {
                std::cout << "Tree is empty.\n";
            }
            break;
        case 5:
            if 
                (BinaryTreeNode* maxNode = tree.FindMax(tree.GetRoot())) 
            {
                std::cout << "Maximum value: " << maxNode->Data << "\n";
            }
            else 
            {
                std::cout << "Tree is empty.\n";
            }
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}