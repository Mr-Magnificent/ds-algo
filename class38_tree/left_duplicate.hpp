#pragma once
#include <bits/stdc++.h>

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

Node *construct(std::vector<char> arr)
{
    Node *root = nullptr;
    std::stack<Node *> stk;

    for (int i = 0; i < arr.size(); i++)
    {
        if ((int)arr[i] == -1)
        {
            stk.pop();
        }
        else
        {
            Node *node = new Node(arr[i]);
            if (stk.empty())
            {
                root = node;
            }
            else
            {
                Node *temp = stk.top();
                if (temp->left == nullptr)
                {
                    temp->left = node;
                }
                else
                {
                    temp->right = node;
                }
            }
            stk.push(node);
        }
    }
    return root;
}

void display(Node *root)
{
    using namespace std;
    if (root == nullptr) {
        return;
    }

    cout  << root->data << " ";

    display(root->left);
    display(root->right);
}