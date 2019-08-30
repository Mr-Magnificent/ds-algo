#include "B_Tree.hpp"
using namespace std;

Node *add(Node *node, int data)
{
    if (node == nullptr)
    {
        Node *temp = new Node(data);
        return temp;
    }

    if (node->data > data)
    {
        node->left = add(node->left, data);
    }
    else
    {
        node->right = add(node->right, data);
    }

    return node;
}

Node *FindLeftMax(Node *node)
{
    if (node->right == nullptr)
    {
        return node;
    }

    return FindLeftMax(node->right);
}

Node *remove(Node *node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data > data)
    {
        node->left = add(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = add(node->right, data);
    }
    else
    {
        if (!node->left || !node->right)
        {
            return (node->left == nullptr) ? node->right : node->left;
        }
        else
        {
            Node *leftMax = FindLeftMax(node->left);
            node->data = leftMax->data;
            remove(leftMax, leftMax->data);
        }
    }
    return node;
}

int main(int argc, char **argv)
{
    vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(arr, 0, arr.size() - 1);

    add(root, 30);
    add(root, 40);
    // add(root, 50);
    add(root, 60);
    add(root, 70);
    add(root, 80);
    add(root, 90);

    display(root);

    remove(root, 50);
    display(root);
}