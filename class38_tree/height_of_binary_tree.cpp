#include "binary_tree.hpp"
using namespace std;

int FindHeightOfBTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int height = 0;
    height = max(FindHeightOfBTree(root->left), FindHeightOfBTree(root->right));
    return height + 1;
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};
    Node *node = construct_tree(arr);

    cout << FindHeightOfBTree(node) << endl;
}