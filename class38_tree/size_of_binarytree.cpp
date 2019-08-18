#include "binary_tree.hpp"
using namespace std;

int FindSizeOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = FindSizeOfTree(root->left);
    sum += FindSizeOfTree(root->right);

    sum++;

    return sum;
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *node = construct_tree(arr);
    
    cout << FindSizeOfTree(node) << endl;
}