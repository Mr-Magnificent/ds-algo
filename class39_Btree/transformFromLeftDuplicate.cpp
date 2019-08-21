#include "left_duplicate.hpp"

void TransformFromLeftDuplicate(Node *root)
{
    if (!root) {
        return;
    }

    Node *temp = root->left->left;
    delete root->left;
    root->left = temp;

    TransformFromLeftDuplicate(root->left);
    TransformFromLeftDuplicate(root->right);
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

    TransformFromLeftDuplicate(root);

    display(root);
    std::cout << std::endl;
}