#include "construct_tree.hpp"
using namespace std;

class PrevNode
{
public:
    Node *prev;

    PrevNode(Node *prev) : prev(prev)
    {
    }
};

void linearise(Node& root, PrevNode &node)
{
    for (int i = root.children.size() - 1; i >= 0; i--)
    {
        linearise(*root.children[i], node);
    }
    if (node.prev != NULL) {
        root.children = vector<Node *>(1, node.prev);
    }
    node.prev = &root;
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);
    PrevNode node = NULL;

    display(*root);
    cout << endl;
    linearise(*root, node);
    display(*root);
    cout << endl;
    cout << root->children.size() << endl;
}