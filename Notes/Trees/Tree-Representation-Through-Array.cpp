#include <iostream>
using namespace std;

// Root of the tree must be stored at 0th index
// If a node is stored at ith Index then:
// The left child must be stored at (2i + 1)th index
// The right child must be stored at (2i + 2)th index
// The parent node must be stored at ((i - 1) / 2) index

class Node
{
    public:
        int * data;
        int size;

        Node(int size)
        {
            data = new int[size];
            this->size = size;
        }

};

class BT
{
    public:
        Node * root;

        BT(int size)
        {
            root = new Node(10);
        }

        void insert(int data)
        {
            insertion(0, data);
        }

        void insertion(int index, int data)
        {
            if(root->data[index] == -1)
            {
                root->data[index] = data;
            }
            else if(data <= root->data[index])
            {
                insertion(2 * index + 1, data);
            }
            else if(data >= root->data[index])
            {
                insertion(2 * index + 2, data);
            }
        }

        void inorder(int index)
        {
            if(index < root->size && root->data[index] != -1)
            {
                inorder((2 * index + 1));
                cout << root->data[index] << " ";
                inorder((2 * index + 2));
            }

            
        }
};

int main()
{
    BT * B = new BT(15);

    for(int i = 0; i < 15; i++)
    {
        B->root->data[i] = -1;
    }

    B->insert(5);
    B->insert(10);
    B->insert(4);
    B->insert(67);
    B->insert(3);
    B->insert(1);

    B->inorder(0);
}