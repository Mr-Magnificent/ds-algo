#pragma once
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    std::vector<Node *> children;

    Node(int data) : data(data)
    {
    }

    Node()
    {
    }
};

Node *construct(std::vector<int> &arr)
{
    Node *root;
    std::stack<Node *> stk;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            stk.pop();
        }
        else
        {
            Node *node = new Node(arr[i]);
            if (stk.size() == 0)
            {
                root = node;
            }
            else
            {
                Node *top = stk.top();
                top->children.push_back(node);
            }
            stk.push(node);
        };
    }
    return root;
}

void display(const Node &root)
{
    std::cout << root.data << " ";

    for (int i = 0; i < root.children.size(); i++)
    {
        display(*root.children[i]);
    }
}
