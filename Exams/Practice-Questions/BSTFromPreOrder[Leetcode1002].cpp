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

        Node * insert(Node *& head, int data)
        {
            if(head == NULL)
            {
                Node * n = new Node(data);

                head = n;

                return head;
            }

            if(data > head->data)
            {
                head->right = insert(head->right, data);
            }
            else if(data < head->data)
            {
                head->left = insert(head->left, data);
            }

            return head;
        }

        Node * preorderBST(Node *& h, vector<int> & v)
        {
            for(int i = 0; i < v.size(); i++)
            {
                h = insert(h, v[i]);
            }

            return h;
        }

        void inorder(Node * r)
        {
            if(r == NULL)
            {
                return;
            }

            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
};

int main()
{
    vector <int> a;

    int b;

    for(int i = 0; i < 8; i++)
    {
        cout << "Enter value: ";

        cin >> b;

        a.push_back(b);
    }

    BST * root = new BST();

    root->preorderBST(root->root, a);

    root->inorder(root->root);
}