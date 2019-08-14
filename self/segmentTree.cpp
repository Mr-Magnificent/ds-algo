#include <bits/stdc++.h>
using namespace std;

template <class T>
T find_mid(T left, T right)
{
    return (left + right) / 2;
}

void constructST(int left, int right, vector<int> &arr, vector<int> &segment_tree)
{
    int mid = find_mid(left, right);
    if (mid == left)
    {
        segment_tree[mid] = 
    }
}

int main(int argc, char **argv)
{
    vector<int> inp({1, 3, 5, 7, 9, 11});
    int st_size = 2 * pow(2, ceil(log2(inp.size()))) - 1;

    vector<int> segment_tree(st_size);
}
