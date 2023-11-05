#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node()
        {

        };

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

};

class BT
{
    public:
        Node * root;

        bool isBST(Node *& root, int min_val, int max_val) 
        {
            if (root == NULL) 
            {
                return true;
            }

            if (root->data <= min_val || root->data >= max_val) 
            {
                return false;
            }

            return isBST(root->left, min_val, root->data) && isBST(root->right, root->data, max_val);
        }

        int counting(Node *& root) 
        {
            if (root == NULL) 
            {
                return 0;
            }

            int count = 0;

            if (isBST(root, INT_MIN, INT_MAX)) 
            {
                count = 1;
            }

            return count + counting(root->left) + counting(root->right);
        }
};