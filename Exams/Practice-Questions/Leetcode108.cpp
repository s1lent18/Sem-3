#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
        int data;
        int height;
        Node * right;
        Node * left;

        Node()
        {

        }

        Node(int data)
        {
            this->data = data;
            height = 1;
            right = NULL;
            left = NULL;
        }
};

class BST
{
    public:
        Node * root;

        int max(int a, int b)
        {
            if(a > b)
            {
                return a;
            }

            return b;
        }

        int getheight(Node *& head)
        {
            if(head == NULL)
            {
                return 0;
            }

            return head->height;
        }

        int getbalancingfactor(Node *& head)
        {
            if(head == NULL)
            {
                return 0;
            }

            return (head->left) - (head->right);
        }

        Node * leftRotate(Node *& root)
        {
            Node * afterroot = root->right;
            Node * temp = afterroot->left;

            afterroot->left = root;
            root->right = temp;

            root->height = max(getheight(root->left), getheight(root->right)) + 1;

            afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;

            return afterroot;
        }

        Node * rightRotate(Node *& root)
        {
            Node * afterroot = root->left;
            Node * temp = afterroot->right;

            afterroot->right = root;
            root->left = temp;

            root->height = max(getheight(root->left), getheight(root->right)) + 1;

            afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;

            return afterroot;
        }

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
            else
            {
                return head;
            }

            head->height = max(getheight(head->left), getheight(head->right)) + 1;

            int balance = getbalancingfactor(head);

            // left right
            if(balance > 1 && data > head->left->data)
            {
                head->left = leftRotate(head->left);
                return rightRotate(head);

            } // left left
            else if(balance > 1 && data < head->left->data)
            {
                return rightRotate(head);
            } // right right
            else if(balance > -1 && data > head->right->data)
            {   
                return leftRotate(head);
            } // right left
            else if(balance < -1 && data < head->right->data)
            {
                head->right = rightRotate(head->right);
                return leftRotate(head);
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
            cout << head->data << " ";
            inorder(head->right);
        }

        void insertion(Node *& head, vector<int> inser)
        {
            for(int i = 0; i < inser.size(); i++)
            {
                head = insert(head, inser[i]);
            }
        }
};

int main()
{
    BST * B = new BST();

    vector<int> leetcode;

    int a;

    for(int i = 0; i < 5; i++)
    {
        cout << "enter value: ";

        cin >> a;

        leetcode.push_back(a);
    }

    B->insertion(B->root, leetcode);

    B->inorder(B->root);
}