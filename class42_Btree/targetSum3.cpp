#include "B_Tree.hpp"
using namespace std;

struct Pair
{
    Node *node;
    int state;

    Pair(Node *node) : node(node), state(0)
    {
    }
};

void printTargetSum(Node *root, int target)
{
    stack<Pair *> ls;
    stack<Pair *> rs;
    ls.push(new Pair(root));
    rs.push(new Pair(root));

    bool moveLeft = true;
    bool moveRight = true;

    int lsVal = 0;
    int rsVal = 0;

    while (true)
    {
        while (moveLeft == true && !ls.empty())
        {
            if (ls.top()->state == 0)
            {
                ls.top()->state++;
                ls.push(new Pair(ls.top()->node->left));
            }
            else if (ls.top()->state == 1)
            {
                ls.top()->state++;
                lsVal = ls.top()->node->data;
                ls.push(new Pair(ls.top()->node->right));
                break;
            }
            else
            {
                ls.pop();
            }
        }

        while (moveRight == true && !rs.empty())
        {
            if (rs.top()->state == 0)
            {
                rs.top()->state++;
                rs.push(new Pair(rs.top()->node->right));
            }
            else if (rs.top()->state == 1)
            {
                rsVal = rs.top()->node->data;
                rs.top()->state++;
                if (rs.top)
                rs.push(new Pair(rs.top()->node->left));
                break;
            } else {
                rs.pop();
            }
        }

        if (lsVal >= rsVal) {
            break;
        }
        else if (lsVal + rsVal < target) {
            moveLeft = true;
            moveRight = false;
        } else if(lsVal + rsVal > target) {
            moveLeft = false;
            moveRight = true;
        } else {
            cout << lsVal << " " << rsVal << endl;
            moveLeft = true;
            moveRight = true;
        }
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

    printTargetSum(root, 80);
}