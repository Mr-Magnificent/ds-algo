#include "b_tree.hpp"
using namespace std;

struct BST
{
    int smallest;
    int largest;
    bool isBST;

    BST(int smallest, int largest, bool isBST)
        : smallest(smallest), largest(largest), isBST(isBST)
    {
    }
};

BST *isBST(Node *root)
{
    if (root == nullptr)
    {
        BST *node = new BST(INT_MAX, INT_MIN, true);
        return node;
    }

    BST *left = isBST(root->left);
    BST *right = isBST(root->right);

    int smallest = min(left->smallest, min(right->smallest, root->data));
    int largest = max(left->largest, max(right->largest, root->data));

    BST *node = new BST(smallest, largest,
                        (left->largest < root->data && right->smallest >= root->data));

    if (!left->isBST || !right->isBST)
    {
        node->isBST = false;
    }

    return node;
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 49, 37, 25, 60, 70, 62, 80, 90, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 49, 50, 60, 62, 70, 75, 80, 87, 90};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    BST *node = isBST(root);
    cout << node->isBST << endl;
}