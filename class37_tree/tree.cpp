#include <bits/stdc++.h>
#include "construct_tree.hpp"
using namespace std;

void display(const Node &root)
{
    cout << root.data << " ";

    for (int i = 0; i < root.children.size(); i++)
    {
        display(*root.children[i]);
    }
}

// void LevelOrderWithZigZag(Node &root)
// {
//     queue<Node *> que;
//     que.push(&root);
//     stack<Node *> stk;
//     stk.push(&root);
//     bool toggle = false;

//     while (!que.empty())
//     {
//         int size = que.size();
//         while (size-- > 0)
//         {
//             for (int i = 0; i < stk.size(); i++)
//             {
//                 cout << stk.top()->data << " ";
//                 stk.pop();
//             }
//             Node remNode = *que.front();
//             que.pop();
//             if (toggle)
//             {
//                 for (int i = 0; i < remNode.children.size(); i++)
//                 {
//                     que.push(remNode.children[i]);
//                     stk.push(remNode.children[i]);
//                 }
//             }
//             else
//             {
//                 for (int i = remNode.children.size() - 1; i >= 0; i--)
//                 {
//                     que.push(remNode.children[i]);
//                     stk.push(remNode.children[i]);
//                 }
//             }
//         }
//         cout << endl;
//         toggle = !toggle;
//     }
// }

// void LevelOrderWithBoundary(Node &root)
// {
//     queue<Node *> que;
//     que.push()
// }

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);
    display(*root);

    // LevelOrder
    // cout << root->children.size() << endl;
}