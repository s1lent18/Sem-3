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

        Node * insert(Node *& root, int data)
        {
            if(root == NULL)
            {
                Node * n = new Node(data);

                root = n;

                return root;
            }

            if(data < root->data)
            {
                root->left = insert(root->left, data);
            }
            else if(data > root->data)
            {
                root->right = insert(root->right, data);
            }

            return root;
        }

        Node * Insertion(Node *& root, vector<int> leetcode)
        {
            for(int i = 0; i < leetcode.size(); i++)
            {
                root = insert(root, leetcode[i]);
            }

            return root;
        }

        void findmin(Node *& root, int previous, int mind)
        {
            if(root == NULL)
            {
                return;
            }

            findmin(root->left, previous, mind);

            if(previous != -1)
            {
                mind = min(mind, root->data - previous);
            }

            previous = root->data;

            findmin(root->right, previous, mind);
        }

        int getMinimumDifference(Node *& root)
        {
            int mind = 2147483647;

            int prev = -1;

            findmin(root, prev, mind);

            return mind;
        }
};  

int main()
{
    BST * B = new BST();

    vector <int> leetcode;

    int a;

    for(int i = 0; i < 7; i++)
    {
        cout << "Enter Value: ";

        cin >> a;

        leetcode.push_back(a);
    }

    B->root = B->Insertion(B->root, leetcode);

    cout << B->getMinimumDifference(B->root);
}