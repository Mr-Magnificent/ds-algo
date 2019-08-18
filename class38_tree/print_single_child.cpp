#include "binary_tree.hpp"
using namespace std;

int printSingleChild(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int val = printSingleChild(root->left);
    val += printSingleChild(root->right);

    if (val == 1)
    {
        
    }

    return 1;
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};
    Node *node = construct_tree(arr);

    printSingleChild(node);
}