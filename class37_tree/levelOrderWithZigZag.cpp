#include "construct_tree.hpp"
using namespace std;

void LevelOrderWithZigZag(Node &root)
{
    stack<Node *> stk1;
    stack<Node *> stk2;
    stk1.push(&root);
    bool toggle = false;

    while (!stk1.empty())
    {
        // int size = stk1.size();
        // while (size-- > 0)
        // {
        Node remNode = *stk1.top();
        cout << remNode.data << " ";
        stk1.pop();
        if (toggle)
        {
            for (int i = 0; i < remNode.children.size(); i++)
            {
                stk2.push(remNode.children[i]);
            }
        }
        else
        {
            for (int i = remNode.children.size() - 1; i >= 0; i--)
            {
                stk2.push(remNode.children[i]);
            }
        }
        // }
        if (stk1.empty())
        {
            cout << endl;
            toggle = !toggle;
            stack<Node *> temp = stk2;
            stk2 = stk1;
            stk1 = temp;
        }
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    LevelOrderWithZigZag(*root);
}