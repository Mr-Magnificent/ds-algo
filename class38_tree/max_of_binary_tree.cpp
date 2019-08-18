#include "binary_tree.hpp"
using namespace std;

int FindMaxOfTree(Node *root)
{
    if (root == NULL) {
        return INT_MIN;
    }

    int left = FindMaxOfTree(root->left);
    int right = FindMaxOfTree(root->right);

    return max(root->data, max(left, right));
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    cout << FindMaxOfTree(root) << endl;
}