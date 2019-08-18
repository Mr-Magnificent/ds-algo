#include "construct_tree.hpp"
using namespace std;

class Limit
{
public:
    int floor;
    int ceil;

    Limit(int floor, int ceil) : floor(floor), ceil(ceil)
    {
    }
};

void findCeilFloor(Node root, int data, Limit &sol)
{
    if (root.data >= data)
    {
        sol.ceil = min(root.data, sol.ceil);
    }

    if (root.data <= data)
    {
        sol.floor = max(root.data, sol.floor);
    }

    for (int i = 0; i < root.children.size(); i++)
    {
        findCeilFloor(*root.children[i], data, sol);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    Limit limitSol(INT_MIN, INT_MAX);
    findCeilFloor(*root, 65, limitSol);
    cout << "Floor of " << 65 << ":\t" << limitSol.floor << endl
         << "Ceil of " << 65 << ":\t" << limitSol.ceil << endl;
}