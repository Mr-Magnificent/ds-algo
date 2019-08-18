#include "binary_tree.hpp"
using namespace std;

bool FindElement(Node *root, int data) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    bool found = FindElement(root->left, data);
    if (found) {
        return found;
    }
    found = FindElement(root->right, data);
    if (found) {
        return found;
    }

    return false;
}

int main(int argc, char **argv) {
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    cout << "Element found: " << FindElement(root, 87) << endl;
}