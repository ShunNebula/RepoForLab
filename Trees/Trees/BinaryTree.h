#pragma once

#include <iostream>

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode* Parent;

	BinaryTreeNode(int data) : Data(data), Left(nullptr), Right(nullptr), Parent(nullptr) {}
};

class BinaryTree 
{
private:
    BinaryTreeNode* _root;
    void DestroyNode(BinaryTreeNode* node);

public:
    BinaryTree();
    ~BinaryTree();

    BinaryTreeNode* GetRoot();
    void Insert(int value);
    BinaryTreeNode* Remove(BinaryTreeNode* node, int value);
    BinaryTreeNode* Find(BinaryTreeNode* node, int value);
    BinaryTreeNode* FindMin(BinaryTreeNode* node);
    BinaryTreeNode* FindMax(BinaryTreeNode* node);
};