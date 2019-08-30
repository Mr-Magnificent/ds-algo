#include "postInOrder.hpp"
using namespace std;

struct Diameter
{
    Node *node;
    int height;
    int diameter;
};

int diameter
{
    
}

int main(int argc, char **argv)
{
    vector<int> post = {12, 30, 37, 25, 70, 62, 87, 75, 50};
    vector<int> in = {12, 25, 30, 37, 50, 62, 70, 75, 87};

    Node *root = construct_tree(post, 0, post.size() - 1, in, 0, in.size() - 1);
}