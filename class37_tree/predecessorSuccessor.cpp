#include "construct_tree.hpp"
using namespace std;

class Predecessor
{
public:
    int prev;
    int predecessor;
    int successor;
    bool found;

    Predecessor(int prev, int predecessor, int successor, bool found)
        : prev(prev), predecessor(predecessor), successor(successor), found(found)
    {
    }
};

void FindPreorder(Node root, int data, Predecessor &sol)
{
    if (sol.found == false && root.data == data)
    {
        sol.found = true;
        sol.predecessor = sol.prev;
    }

    if (sol.found == true && sol.prev == data)
    {
        sol.successor = root.data;
    }

    sol.prev = root.data;
    for (int i = 0; i < root.children.size(); i++)
    {
        FindPreorder(*root.children[i], data, sol);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    Predecessor solPre(-1, -1, -1, false);
    FindPreorder(*root, 80, solPre);
    cout << "Element found: \t\t\t" << solPre.found << endl
         << "Predecessor of element is: \t" << solPre.predecessor << endl
         << "Successor of element is: \t" << solPre.successor << endl;
}