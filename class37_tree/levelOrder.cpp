#include "construct_tree.hpp"
using namespace std;

void LevelOrder(Node &root)
{
    queue<Node *> que;
    que.push(&root);
    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            Node remNode = *que.front();
            cout << remNode.data << " ";
            que.pop();
            for (int i = 0; i < remNode.children.size(); i++)
            {
                que.push(remNode.children[i]);
            }
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1,
                       120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    Node *root = construct(arr);

    LevelOrder(*root);
}