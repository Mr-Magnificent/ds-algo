#include "b_tree.hpp"
using namespace std;

static void printKDown(Node *node, int k) {
    if (node == nullptr) {
        return;
    }
    if (k == 0) {
        cout << node->data << " ";
    }

    printKDown(node->left, k - 1);
    printKDown(node->right, k - 1);
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 51, 37, 25, 60, 70, 62, 80, 90, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 51, 50, 60, 62, 70, 75, 80, 87, 90};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);

    printKDown(root, 3);
    cout << endl;
}