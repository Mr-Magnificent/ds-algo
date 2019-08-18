#include "construct_tree.hpp"
using namespace std;

class HMPair
{
public:
    int max;
    int min;
    bool found;

    HMPair(int x, bool found) : max(x), min(x), found(found)
    {
    }

    HMPair(int min, int max, bool found) : min(min), max(max), found(found)
    {
    }
};

void multiSolver(Node root, int data, HMPair &sol)
{
    if (sol.found == false && root.data == data)
    {
        sol.found = true;
    }

    sol.max = max(sol.max, root.data);
    sol.min = min(sol.min, root.data);

    for (int i = 0; i < root.children.size(); i++)
    {
        multiSolver(*root.children[i], data, sol);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    HMPair sol(INT_MAX, INT_MIN, false);

    multiSolver(*root, 80, sol);
    cout << "Data found " << sol.found << endl
         << "Minimum in tree " << sol.min << endl
         << "Maximum in tree " << sol.max << endl;
}