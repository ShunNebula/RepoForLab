#include "BinaryTree.h"
#include <iostream> 

void BinaryTree::DestroyNode(BinaryTreeNode* node)
{
	if (node != nullptr)
	{
		DestroyNode(node->Left);
		DestroyNode(node->Right);
		delete node;
	}
}

BinaryTree::BinaryTree() : _root(nullptr) {}

BinaryTree::~BinaryTree()
{
	DestroyNode(_root);
}

BinaryTreeNode* BinaryTree::GetRoot()
{
	return _root;
}

void BinaryTree::Insert(int value)
{
	BinaryTreeNode** cur = &_root;
	BinaryTreeNode* parent = nullptr;

	while (*cur)
	{
		parent = *cur;
		BinaryTreeNode& node = **cur;
		if (value < node.Data)
		{
			cur = &node.Left;
		}
		else if (value > node.Data)
		{
			cur = &node.Right;
		}
		else
		{
			return;
		}
	}
	*cur = new BinaryTreeNode(value);
	(*cur)->Parent = parent;
}

BinaryTreeNode* BinaryTree::Remove(BinaryTreeNode* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (value < node->Data)
	{
		node->Left = Remove(node->Left, value);
		if (node->Left)
		{
			node->Left->Parent = node;
		}
	}
	else if (value > node->Data)
	{
		node->Right = Remove(node->Right, value);
		if (node->Right)
		{
			node->Right->Parent = node;
		}
	}
	else {
		// Нет дочерних узлов
		if (node->Left == nullptr && node->Right == nullptr)
		{
			if (node->Parent)
			{
				if (node->Parent->Left == node)
				{
					node->Parent->Left = nullptr;
				}
				else
				{
					node->Parent->Right = nullptr;
				}
			}
			delete node;
			return nullptr;
		}

		// Один дочерний узел (правый)
		if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node->Right;
			if (node->Parent)
			{
				if (node->Parent->Left == node)
				{
					node->Parent->Left = temp;
				}
				else
				{
					node->Parent->Right = temp;
				}
			}
			temp->Parent = node->Parent;
			delete node;
			return temp;
		}

		// Один дочерний узел (левый)
		if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node->Left;
			if (node->Parent)
			{
				if (node->Parent->Left == node)
				{
					node->Parent->Left = temp;
				}
				else
				{
					node->Parent->Right = temp;
				}
			}
			temp->Parent = node->Parent;
			delete node;
			return temp;
		}

		// Два дочерних узла
		BinaryTreeNode* minRight = FindMin(node->Right);
		node->Data = minRight->Data;
		node->Right = Remove(node->Right, minRight->Data);
		if (node->Right)
		{
			node->Right->Parent = node;
		}
	}
	return node;
}

BinaryTreeNode* BinaryTree::Find(BinaryTreeNode* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Data == value)
	{
		return node;
	}
	if (node->Data > value)
	{
		return Find(node->Left, value);
	}
	else
	{
		return Find(node->Right, value);
	}
}


BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Left != nullptr)
	{
		node = node->Left;
	}
	return node;
}

BinaryTreeNode* BinaryTree::FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->Right != nullptr)
	{
		node = node->Right;
	}
	return node;
}




