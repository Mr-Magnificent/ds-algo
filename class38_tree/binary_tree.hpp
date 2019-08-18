#pragma once
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL)
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

// Node *construct_tree(std::vector<int> arr)
// {
//     Node *root = NULL;
//     std::stack<Node> stk;

//     for (int ele : arr)
//     {
//         if (ele == -1)
//         {
//             stk.pop();
//         }
//         else
//         {
//             Node *node = new Node(ele);
//             if (stk.size() == 0)
//             {
//                 root = node;
//             }
//             else
//             {
//                 Node item = stk.top();
//                 if (stk.top().left == NULL)
//                 {
//                     stk.top().left = node;
//                 }
//                 else
//                 {
//                     stk.top().right = node;
//                 }
//             }
//             stk.push(*node);
//         }
//     }
//     return root;
// }

void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->data << " ";
    display(root->left);
    display(root->right);
}
