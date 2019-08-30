#include "B_Tree.hpp"
using namespace std;

int sum = 0;

void transformToGreater(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    transformToGreater(node->right);
    int temp = node->data;
    node->data = sum;
    sum += temp;
    transformToGreater(node->left);
}

int main(int argc, char **argv)
{
    vector<int> arr = {12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(arr, 0, arr.size() - 1);

    display(root);
    cout << endl;
    transformToGreater(root);
    display(root);
}