#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

int findIndex(const vector<int> &arr, int value, int inStartIndx, int inEndIndx)
{
    for (int i = inStartIndx; i <= inEndIndx; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node *construct_tree(const vector<int> &pre, int preStartIndx, int preEndIndx,
                     const vector<int> &in, int inStartIndx, int inEndIndx)
{
    if (inStartIndx > inEndIndx || preStartIndx > preEndIndx)
    {
        return nullptr;
    }

    Node *node = new Node(pre[preStartIndx]);

    int temp = findIndex(in, pre[preStartIndx], inStartIndx, inEndIndx);

    int lhs = temp - inStartIndx;

    node->left = construct_tree(pre, preStartIndx + 1, preStartIndx + lhs,
                                in, inStartIndx, temp - 1);

    node->right = construct_tree(pre, preStartIndx + lhs + 1, preEndIndx,
                                 in, temp + 1, inEndIndx);

    return node;
}

void display(Node *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int main(int argc, char **argv)
{
    vector<int> pre = {50, 25, 12, 37, 30, 75, 62, 70, 87};
    vector<int> in = {12, 25, 30, 37, 50, 62, 70, 75, 87};

    Node *root = construct_tree(pre, 0, pre.size() - 1, in, 0, in.size() - 1);

    display(root);
}