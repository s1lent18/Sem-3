#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

// Reversing a binary/binary-search Tree
Node * reverseTree(Node * root)
{
    if(root == NULL)
    {
        return NULL; 
    }

    swap(root->left, root->right);

    root->left = reverseTree(root->left);
    root->right = reverseTree(root->right);

    return root;
}