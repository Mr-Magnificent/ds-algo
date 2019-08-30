#include "B_Tree.hpp"
using namespace std;



int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 30, 50, 60, 70, 80};
    Node *root = construct(arr, 0, arr.size() - 1);

    add(root, 25);
    add(root, 35);
    add(root, 55);
    add(root, 65);

    
}