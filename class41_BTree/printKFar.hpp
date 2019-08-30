#include "b_tree.hpp"

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
