#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node()
        {

        }

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public:
        Node * root;

        Node * insert(Node *& root, int data)
        {
            if(root == NULL)
            {
                Node * n = new Node(data);

                return n;
            }

            if(data < root->data)
            {
                root->left = insert(root->left, data);
            }
            if(data > root->data)
            {
                root->right = insert(root->right, data);
            }

            return root;
        }

        Node * Reverse(Node *& root)
        {
            if(root == NULL)
            {
                return NULL;
            }

            Node * temp = root->left;
            root->left = root->right;
            root->right = temp;

            Reverse(root->left);
            Reverse(root->right);

            return root;
        }

        void inorder(Node * root)
        {
            if(root == NULL)
            {
                return;
            }

            inorder(root->left);
            cout << root-> data << " ";
            inorder(root->right);
        }  
};

int main()
{
    BST * B = new BST();

    B->root = B->insert(B->root, 5);
    B->root = B->insert(B->root, 3);
    B->root = B->insert(B->root, 10);
    B->root = B->insert(B->root, 87);
    B->root = B->insert(B->root, 21);
    B->root = B->insert(B->root, 67);
    B->root = B->insert(B->root, 54);

    B->inorder(B->root);

    cout << endl;

    B->root = B->Reverse(B->root);

    B->inorder(B->root);
}