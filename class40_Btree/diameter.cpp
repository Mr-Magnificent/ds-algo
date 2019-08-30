#include "postInOrder.hpp"
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

int FindDiameter(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int d1 = FindDiameter(root->left);
    int d2 = FindDiameter(root->right);

    int h1 = FindHeightOfBTree(root->left);
    int h2 = FindHeightOfBTree(root->right);
    int maxDia = max(h1 + h2 + 1, max(d1, d2));

    return maxDia;
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 37, 25, 70, 62, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 50, 62, 70, 75, 87};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    cout << FindDiameter(root) << endl;
}