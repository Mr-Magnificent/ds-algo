#include "b_tree.hpp"
using namespace std;

struct Balanced
{
    int height;
    bool isBalanced;

    Balanced(int height, bool isBalanced) : height(height), isBalanced(isBalanced)
    {
    }
};

Balanced *isBalanced(Node *root)
{
    if (root == nullptr)
    {
        Balanced *b = new Balanced(0, true);
        return b;
    }

    Balanced *left = isBalanced(root->left);
    Balanced *right = isBalanced(root->right);

    Balanced *node = new Balanced(max(left->height, right->height) + 1, true);

    if (!left->isBalanced || !right->isBalanced)
    {
        node->isBalanced = false;
        return node;
    }

    if (abs(left->height - right->height) > 1)
    {
        node->isBalanced = false;
        return node;
    }

    return node;
}

int main(int argc, char **argv)
{
    vector<int> post = {30, 20, 50, 40, 10};
    vector<int> in = {30, 20, 10, 40, 50};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    Balanced *node = isBalanced(root);
    cout << node->isBalanced << endl;
}