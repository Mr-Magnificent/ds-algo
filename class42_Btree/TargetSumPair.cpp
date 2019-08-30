#include "B_Tree.hpp"
using namespace std;

int FindItem(Node *node, int data)
{
    if (node == nullptr)
    {
        return -1;
    }
    if (node->data == data)
    {
        return data;
    }
    else if (node->data > data)
    {
        return FindItem(node->left, data);
    }
    else
    {
        return FindItem(node->right, data);
    }
}

void targetSumPair(Node *root, Node *node, int data)
{
    if (node == nullptr)
    {
        return;
    }

    int val = FindItem(root, data - node->data);
    if (val != -1 && val > node->data) {
        cout << node->data << " + " << val << endl;
    }
    targetSumPair(root, node->left, data);
    targetSumPair(root, node->right, data);
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 30, 50, 60, 70, 80};
    Node *root = construct(arr, 0, arr.size() - 1);

    add(root, 25);
    add(root, 35);
    add(root, 55);
    add(root, 65);
    display(root);
    targetSumPair(root, root, 125);
}