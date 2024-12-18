#pragma once
#include <iostream>

#include "TreapNode.h"

class Treap
{
private:
    TreapNode* root;

    void split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
    {
        if (node == nullptr)
        {
            left = right = nullptr;
        }
        else if (node->key <= key)
        {
            split(node->right, key, node->right, right);
            left = node;
        }
        else
        {
            split(node->left, key, left, node->left);
            right = node;
        }
    }

    TreapNode* merge(TreapNode* left, TreapNode* right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == nullptr ? right : left;
        }

        if (left->priority > right->priority)
        {
            left->right = merge(left->right, right);
            return left;
        }
        right->left = merge(left, right->left);
        return right;
    }

    void insert(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            node = new TreapNode(key);
            return;
        }

        if (key < node->key)
        {
            insert(node->left, key);
            if (node->left->priority > node->priority)
            {
                node = merge(node->left, node);
            }
        }
        else if (key > node->key)
        {
            insert(node->right, key);
            if (node->right->priority > node->priority)
            {
                node = merge(node, node->right);
            }
        }
        else
        {
            throw "Duplicate keys are not allowed.";
        }
    }

    void remove(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            throw "Key not found.";
        }

        if (key < node->key)
        {
            remove(node->left, key);
        }
        else if (key > node->key)
        {
            remove(node->right, key);
        }
        else
        {
            TreapNode* temp = node;
            node = merge(node->left, node->right);
            delete temp;
        }
    }

    void inorder(TreapNode* node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            std::cout << node->key << " ";
            inorder(node->right);
        }
    }

public:
    Treap() : root(nullptr) {}

    void insert(int key)
    {
        insert(root, key);
    }

    void remove(int key)
    {
        remove(root, key);
    }

    void inorder()
    {
        inorder(root);
        std::cout << std::endl;
    }
};
