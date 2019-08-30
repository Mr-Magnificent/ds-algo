#include "printKFar.hpp"
using namespace std;

int printKFar(Node *root, int data, int k)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == data)
    {
        printKDown(root, k);
        return 1;
    }

    int left = printKFar(root->left, data, k);
    if (left != -1)
    {
        if (left == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKDown(root->right, k - left - 1);
        }
        return left + 1;
    }

    int right = printKFar(root->right, data, k);
    if (right != -1)
    {
        if (right == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKDown(root->left, k - right - 1);
        }
        return right + 1;
    }
    return -1;
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 51, 37, 25, 60, 70, 62, 80, 90, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 51, 50, 60, 62, 70, 75, 80, 87, 90};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    printKFar(root, 51, 5);
    cout << endl;
}