#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        cout << root->left->data << " " << root->data << " " << root->right->data << endl;
    }
    else if (root->left)
    {
        cout << root->left->data << " " << root->data << " ." << endl;
    }
    else if (root->right)
    {
        cout << ". " << root->data << " " << root->right->data << endl;
    }
    display(root->left);
    display(root->right);
}

Node *construct(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;

    Node *node = new Node(arr[mid]);

    node->left = construct(arr, start, mid - 1);
    node->right = construct(arr, mid + 1, end);

    return node;
}

int FindMin(Node *node)
{
    if (node == nullptr)
    {
        return INT_MAX;
    }

    int left = FindMin(node->left);
    int right = FindMin(node->right);

    return min(left, min(right, node->data));
}

int FindMax(Node *node)
{
    if (node == nullptr)
    {
        return INT_MIN;
    }

    int left = FindMax(node->left);
    int right = FindMax(node->right);

    return max(left, max(right, node->data));
}

int main(int argc, char **argv)
{
    vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(arr, 0, arr.size() - 1);

    cout << "Min:\t" << FindMin(root) << endl
         << "Max:\t" << FindMax(root) << endl;

    cout << endl;
    display(root);
    cout << endl;
}
