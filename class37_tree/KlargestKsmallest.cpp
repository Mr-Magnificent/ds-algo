#include "construct_tree.hpp"
using namespace std;

void FindLimitLargest(Node root, int &solLargest, int limitLarge,
                      int &solSmallest, int limitSmall)
{
    if (root.data < limitLarge)
    {
        solLargest = max(root.data, solLargest);
    }

    if (root.data > limitSmall)
    {
        solSmallest = min(root.data, solSmallest);
    }

    for (int i = 0; i < root.children.size(); i++)
    {
        FindLimitLargest(*root.children[i], solLargest,
                         limitLarge, solSmallest, limitSmall);
    }
}

void FindKLargest(Node root, int k)
{
    int val1 = INT_MAX;
    int val2 = INT_MIN;
    int solLargest = INT_MIN;
    int solSmallest = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        solLargest = INT_MIN;
        solSmallest = INT_MAX;
        FindLimitLargest(root, solLargest, val1, solSmallest, val2);
        val1 = solLargest;
        val2 = solSmallest;
        // cout << sol;
    }
    cout << k << "th smallest:\t" << val1 << endl
         << k << "th largest: \t" << val2 << endl;
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    FindKLargest(*root, 6);
}