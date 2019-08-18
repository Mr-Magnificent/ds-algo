#include "binary_tree.hpp"
using namespace std;

void RemoveChild(Node *root)
{
    
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1,
                       75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *node = construct_tree(arr);

    RemoveChild(node);
}