#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        int data;
        int height;
        Node * left;
        Node * right;

        Node(int data)
        {
            this->data = data;
            height = 1;
            left = NULL;
            right = NULL;
        }

};

int getheight(Node * n)
{
    if(n == 0)
    {
        return 0;
    }

    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node * rotateright(Node * root)
{
    Node * afterroot = root->left;
    Node * temp = afterroot->right; // for holding the address so it doesn't get lost

    afterroot->right = root;
    root->left = temp;

    // updating the heights

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    
    afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;

    return afterroot;
}

Node * rotateleft(Node * root)
{
    Node * afterroot = root->right;
    Node * temp = afterroot->left;  // for holding the address so it doesn't get lost

    afterroot->left = root;
    root->right = temp;

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    
    afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;

    return afterroot;
}

int getbalancingfactor(Node * n)
{
    if(n == NULL)
    {
        return 0;
    }

    return getheight(n->left) - getheight(n->right);
}

Node * insert(Node * root, int data)
{
    // Step-1:
        // If the node is empty then:
        if(root == NULL)  
        {
            Node * n = new Node(data);

            return n;
        }

        // If the value is less than the current node's value i.e insert at left
        if(data < root->data)
        {
            root->left = insert(root->left, data);
        }

        // If the value is greater than the current node's value i.e insert at right
        if(data > root->data)
        {
            root->right = insert(root->right, data);
        }

        // if the value is equals to the current node i.e Not allowed in BST
        if(data == root->data)
        {
            return root;
        }

    // Step-2:
        // Updating the height of the previous Node
        root->height = max(getheight(root->left), getheight(root->right)) + 1;  

    // Step-3:
        // Checking the balancing factor of its preceding node to determine if a node has become unbalanced
        int balance = getbalancingfactor(root);

        // If the node is unbalanced:

        // Case-1 -> Left-Left Case
        if(balance > 1 && data < root->left->data)
        {
            return rotateright(root);
        }

        // Case-2 -> Right-Right Case:
        if(balance < -1 && data > root->right->data)
        {
            return rotateleft(root);
        }

        // Case-3 -> Left-Right Case:
        if(balance > 1 && data > root->left->data)
        {
            root->left = rotateleft(root->left);
            return rotateright(root);
        }

        // Case-4 -> Right-Left Case:
        if(balance < -1 && data < root->right->data)
        {
            root->right = rotateright(root->right);
            return rotateleft(root);
        }

        return root;
}

void preorder(Node * n)
{
    if(n == NULL)
    {
        return;
    }

    cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

int main()
{
    Node * root;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preorder(root);
}