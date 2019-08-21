#include "binary_tree.hpp"
using namespace std;

vector<string> PathInRange(Node *root, int sum_so_far, int limit_begin, int limit_end)
{
    // cout << root->data << " ";

    vector<string> sol;
    if (root->left != NULL && root->right != NULL)
    {
        vector<string> temp = PathInRange(root->left, sum_so_far + root->data, limit_begin, limit_end);
        if (temp.size() > 0)
        {
            for (string s : temp)
            {
                sol.push_back(to_string(root->data) + " " + s);
            }
        }

        temp = PathInRange(root->right, sum_so_far + root->data, limit_begin, limit_end);
        if (temp.size() > 0)
        {
            for (string s : temp)
            {
                sol.push_back(to_string(root->data) + " " + s);
            }
        }
    }

    else if (root->left != NULL)
    {
        vector<string> temp = PathInRange(root->left, sum_so_far + root->data, limit_begin, limit_end);
        if (temp.size() > 0)
        {
            for (string s : temp)
            {
                sol.push_back(to_string(root->data) + " " + s);
            }
        }
    }
    else if (root->right != NULL)
    {
        vector<string> temp = PathInRange(root->right, sum_so_far + root->data, limit_begin, limit_end);
        if (temp.size() > 0)
        {
            for (string s : temp)
            {
                sol.push_back(to_string(root->data) + " " + s);
            }
        }
    }
    else
    {
        sum_so_far += root->data;
        if (sum_so_far >= limit_begin && sum_so_far <= limit_end)
        {
            // cout << sum_so_far << endl;
            sol.push_back(to_string(root->data));
        }
    }
    return sol;
}

int main(int argc, char **argv)
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};

    Node *root = construct_tree(arr);

    // display(root);

    vector<string> sol = PathInRange(root, 0, 150, 250);

    for (string s : sol)
    {
        cout << s << endl;
    }
}