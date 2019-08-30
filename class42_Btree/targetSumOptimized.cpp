#include "B_Tree.hpp"
using namespace std;

stack<Node *> stk;

void targetSumOptimized(Node *node, int target) {
    if (node == nullptr) {
        return;
    }

    if (node->data + stk.top()->data == target) {
        cout << node->data << " + " << stk.top()->data << endl;
    } else if (node->data + stk.top()->data > target) {
        targetSumOptimized(node->left, target);
    } else {
        stk.push(stk.top()->right);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 30, 50, 60, 70, 80};
    Node *root = construct(arr, 0, arr.size() - 1);

    add(root, 25);
    add(root, 35);
    add(root, 55);
    add(root, 65);

    stk.push(root);

}