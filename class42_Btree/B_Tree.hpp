#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

Node *add(Node *node, int data)
{
    if (node == nullptr)
    {
        Node *temp = new Node(data);
        return temp;
    }

    if (node->data > data)
    {
        node->left = add(node->left, data);
    }
    else
    {
        node->right = add(node->right, data);
    }

    return node;
}

void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        cout << root->left->data << " " << root->data << " " << root->right->data << endl;
    }
    else if (root->left)
    {
        cout << root->left->data << " " << root->data << " ." << endl;
    }
    else if (root->right)
    {
        cout << ". " << root->data << " " << root->right->data << endl;
    }
    display(root->left);
    display(root->right);
}

Node *construct(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    Node *node = new Node(arr[mid]);

    node->left = construct(arr, start, mid - 1);
    node->right = construct(arr, mid + 1, end);

    return node;
}