#pragma once

struct TreapNode
{
    int key;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int k) : key(k), priority(10), left(nullptr), right(nullptr) {}
};