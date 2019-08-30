#include "b_tree.hpp"
using namespace std;

struct LargestBST
{
    int largest;
    int smallest;
    int size;
    bool isBST;

    LargestBST(int smallest, int largest, int size, bool isBST)
        : smallest(smallest), largest(largest), size(size), isBST(isBST)
    {
    }
};

LargestBST *FindLargestBST(Node *root)
{
    if (root == nullptr)
    {
        LargestBST *node = new LargestBST(INT_MAX, INT_MIN, 0, true);
        return node;
    }

    LargestBST *left = FindLargestBST(root->left);
    LargestBST *right = FindLargestBST(root->right);

    bool isBST = left->isBST && right->isBST;
    int smallest = min(left->smallest, min(right->smallest, root->data));
    int largest = max(right->largest, max(left->largest, root->data));

    if (root->data > left->largest && root->data < right->smallest)
    {
        if (isBST)
        {
            LargestBST *node = new LargestBST(smallest, largest, left->size + right->size + 1, true);
            return node;
        }
        else
        {
            LargestBST *node = new LargestBST(smallest, largest, max(left->size, right->size), false);
            return node;
        }
    }

    LargestBST *node = new LargestBST(smallest, largest, max(left->size, right->size), false);
    return node;
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 49, 37, 25, 60, 70, 62, 80, 90, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 49, 50, 60, 62, 70, 75, 80, 87, 90};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    LargestBST *node = FindLargestBST(root);
    cout << node->isBST << " " << node->size << endl;
}