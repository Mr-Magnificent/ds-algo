#include "left_duplicate.hpp"

void TransformToLeftDuplicate(Node *root)
{
    if (root->left != nullptr && root->right != nullptr)
    {
        TransformToLeftDuplicate(root->left);
        TransformToLeftDuplicate(root->right);

        Node *temp = new Node(root->data);
        temp->left = root->left;
        root->left = temp;
    }
    else if (root->right != nullptr)
    {
        TransformToLeftDuplicate(root->right);

        Node *temp = new Node(root->data);
        root->left = temp;
    }
    else if (root->left != nullptr)
    {
        TransformToLeftDuplicate(root->left);

        Node *temp = new Node(root->data);
        temp->left = root->left;
        root->left = temp;
    }
    else
    {
        Node *temp = new Node(root->data);
        root->left = temp;

        return;
    }
}

int main(int argc, char **argv)
{
    std::vector<char> arr{'a', 'b', 'd', -1, 'e', -1, -1, 'c', 'f', -1, 'g', -1, -1, -1};
    Node *root = construct(arr);

    display(root);
    std::cout << std::endl;

    TransformToLeftDuplicate(root);

    display(root);
    std::cout << std::endl;
}