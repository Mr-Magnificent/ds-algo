// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};



int main(int argc, char **argv)
{
    queue<Node *> que;
    que.push();
    
}