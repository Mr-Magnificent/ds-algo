#pragma once
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data) : data(data), left(NULL), right(NULL), parent(NULL)
    {
    }
};

Node *construct_tree(std::vector<int> arr)
{
    Node *root = NULL;
    std::stack<Node *> stk;

    for (int ele : arr)
    {
        if (ele == -1)
        {
            stk.pop();
        }
        else
        {
            Node *node = new Node(ele);
            if (stk.size() == 0)
            {
                root = node;
            }
            else
            {
                Node *item = stk.top();
                if (item->left == NULL)
                {
                    item->left = node;
                }
                else
                {
                    item->right = node;
                }
            }
            stk.push(node);
        }
    }
    return root;
}

void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->parent)
    {
        std::cout << root->data << "@" << root->parent->data << " ";
    }
    else
    {
        std::cout << root->data << " ";
    }
    display(root->left);
    display(root->right);
}
