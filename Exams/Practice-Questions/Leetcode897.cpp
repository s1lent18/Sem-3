#include <iostream>
#include <vector>
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

class BST
{
    public:
        Node * root;
        vector<int> update;

        Node * insert(Node *& head, int data)
        {
            if(head == NULL)
            {
                Node * n = new Node(data);

                head = n;

                return head;
            }

            if(data < head->data)
            {
                head->left = insert(head->left, data);
            }
            else if(data > head->data)
            {
                head->right = insert(head->right, data);
            }

            return head;
        }

        void inorder(Node * head)
        {
            if(head == NULL)
            {
                return;
            }

            inorder(head->left);
            update.push_back(head->data);
            inorder(head->right);
        }

        Node * change(Node *& head)
        {
            Node * r;

            inorder(head);

            for(int i = 0; i < update.size(); i++)
            {
                r = insert(head, update[i]);
            }
        }

        void preorder(Node * root)
        {
            if(root == NULL)
            {
                return;
            }

            cout << root->data << " ";

            preorder(root->left);
            preorder(root->right);
        }
};

int main()
{
    BST * B = new BST();

    B->root = B->insert(B->root, 5);
    B->root = B->insert(B->root, 3);
    B->root = B->insert(B->root, 6);
    B->root = B->insert(B->root, 2);
    B->root = B->insert(B->root, 4);
    B->root = B->insert(B->root, 1);
    B->root = B->insert(B->root, 8);
    B->root = B->insert(B->root, 7);
    B->root = B->insert(B->root, 9);

    B->root = B->change(B->root);

    B->preorder(B->root);
}