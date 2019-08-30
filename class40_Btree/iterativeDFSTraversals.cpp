#include "postInOrder.hpp"
using namespace std;

struct State
{
    Node *node;
    int state;

    State(Node *node) : node(node), state(0)
    {
    }
};

void iterativeDFTraversals(Node *root)
{
    vector<int> pre;
    vector<int> in;
    vector<int> post;

    stack<State *> stk;
    stk.push(new State(root));

    while (!stk.empty())
    {
        State *remNode = stk.top();
        if (remNode == nullptr)
        {
            stk.pop();
        }
        else if (remNode->state == 2)
        {
            post.push_back(remNode->node->data);
            stk.pop();
        }

        else if (remNode->state == 1)
        {
            in.push_back(remNode->node->data);
            stk.top()->state++;
            if (remNode->node->right)
            {
                stk.push(new State(remNode->node->right));
            }
        }

        else if (remNode->state == 0)
        {
            pre.push_back(remNode->node->data);
            stk.top()->state++;
            if (remNode->node->left)
            {
                stk.push(new State(remNode->node->left));
            }
        }
    }

    cout << "pre -> ";
    for (int ele : pre)
    {
        cout << ele << " ";
    }

    cout << endl;
    cout << "in -> ";
    for (int ele : in)
    {
        cout << ele << " ";
    }

    cout << endl;
    cout << "post -> ";
    for (int ele : post)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 37, 25, 70, 62, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 50, 62, 70, 75, 87};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    iterativeDFTraversals(root);
}