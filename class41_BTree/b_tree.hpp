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

int Find_Index(const vector<int> &in, int si, int ei, int data)
{
    for (int i = si; i <= ei; i++)
    {
        if (in[i] == data)
        {
            return i;
        }
    }

    return 0;
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

Node *construct_tree(const vector<int> &post, int psi, int pei,
                     const vector<int> &in, int isi, int iei)
{
    if (psi > pei || isi > iei)
    {
        return nullptr;
    }

    Node *node = new Node(post[pei]);

    int idx = Find_Index(in, isi, iei, post[pei]);
    int lhs = idx - isi;

    node->left = construct_tree(post, psi, psi + lhs-1 , in, isi, idx - 1);
    node->right = construct_tree(post, psi + lhs, pei - 1, in, idx + 1, iei);

    return node;
}