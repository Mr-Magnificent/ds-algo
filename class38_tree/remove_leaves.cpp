#include "binary_tree.hpp"
using namespace std;

int RemoveLeaves(Node *root)
{
    if (root == NULL) {
        return 1;
    }

    int count1 = 0;
    count1 = RemoveLeaves(root->left);
    if (count1 == 2) {
        delete root->left;
        root->left = NULL;
    }

    int count2 = 0;
    count2 = RemoveLeaves(root->right);
    if (count2 == 2) {
        delete root->right;
        root->right = NULL;
    }

    return count1 + count2;
    
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    display(root);
    cout << endl;

    RemoveLeaves(root);

    display(root);
    cout << endl;
}