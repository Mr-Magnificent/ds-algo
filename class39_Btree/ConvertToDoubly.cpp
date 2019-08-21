#include "binary_tree.hpp"
using namespace std;

void convertToDoubly(Node *root)
{
    if (root->left && root->right)
    {
        Node *temp;
        temp = root->left;
        root->left->parent = root;
        root->right->parent = root;

        convertToDoubly(root->left);
        convertToDoubly(root->right);
    }
    else if (root->left)
    {
        root->left->parent = root;

        convertToDoubly(root->left);
    }
    else if (root->right)
    {
        root->right->parent = root;

        convertToDoubly(root->right);
    }
    else
    {
        return;
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    convertToDoubly(root);

    display(root);
    cout << endl;
}