#include "binary_tree.hpp"
using namespace std;

vector<Node *> path_to_node (Node *root, int data) {
    if (root == NULL) {
        return vector<Node *>();
    }

    if (root->data == data) {
        vector<Node *> v;
        v.push_back(new Node(data));
        return v;
    }

    vector<Node *> sol;
    sol = path_to_node(root->left, data);

    if (sol.size() > 0) {
        sol.push_back(root);
        return sol;
    }

    sol = path_to_node(root->right, data);

    if (sol.size() > 0) {
        sol.push_back(root);
        return sol;
    }

    return sol;
}

int main(int argc, char **argv) {
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    vector<Node *> path = path_to_node(root, 70);

    for (Node *node: path) {
        cout << node->data << " ";
    }
    cout << endl;
}