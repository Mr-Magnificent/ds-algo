#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int ht;
    int bal;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        ht = 1;
        bal = 0;
    }
};

int getht(Node *node)
{
    int lh = node->left != nullptr ? node->left->ht : 0;
    int rh = node->right != nullptr ? node->right->ht : 0;

    return max(lh, rh) + 1;
}

int getbal(Node *node)
{
    int lb = node->left != nullptr ? node->left->ht : 0;
    int rb = node->right != nullptr ? node->right->ht : 0;

    return lb - rb;
}

void display(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        cout << root->left->data << " " << root->data << "_" << root->ht << "_" << root->bal << " " << root->right->data << endl;
    }
    else if (root->left)
    {
        cout << root->left->data << " " << root->data << "_" << root->ht << "_" << root->bal << "  ." << endl;
    }
    else if (root->right)
    {
        cout << ".  " << root->data << "_" << root->ht << "_" << root->bal << " " << root->right->data << endl;
    } else {
        cout << ".  " << root->data << "_" << root->ht << "_" << root->bal << "  ." << endl;

    }
    display(root->left);
    display(root->right);
}

Node *RotateRight(Node *x)
{
    Node *y = x->left;
    Node *t3 = y->right;
    y->right = x;
    x->left = t3;

    x->ht = getht(x);
    x->bal = getbal(x);
    y->ht = getht(y);
    y->bal = getbal(y);

    return y;
}

Node *RotateLeft(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;

    x->ht = getht(x);
    x->bal = getbal(x);
    y->ht = getht(y);
    y->bal = getbal(y);

    return y;
}

Node *add(Node *node, int data)
{
    if (node == nullptr)
    {
        Node *temp = new Node(data);
        return temp;
    }
    else if (node->data > data)
    {
        node->left = add(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = add(node->right, data);
    }
    else
    {
    }

    node->ht = getht(node);
    node->bal = getbal(node);

    if (node->bal > 1)
    {
        if (node->left->bal >= 0)
        {
            // LL
            node = RotateRight(node);
        }
        else
        {
            // LR
            node->left = RotateLeft(node->left);
            node = RotateRight(node);
        }
    }
    else if (node->bal < -1)
    {
        if (node->right->bal <= 0)
        {
            // RR
            node = RotateLeft(node);
        }
        else
        {
            // RL
            node->right = RotateRight(node->right);
            node = RotateLeft(node);
        }
    }

    return node;
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

    node->ht = getht(node);
    node->bal = getbal(node);

    return node;
}

int main(int argc, char **argv)
{
    vector<int> arr = {12, 25, 37, 50, 75, 62, 87};
    Node *root = construct(arr, 0, arr.size() - 1);

    add(root, 30);
    add(root, 28);
    add(root, 27);


    display(root);
    cout << endl;
}