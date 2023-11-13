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

class BST
{
    public:
        Node * root;

        BST()
        {
            root = NULL;
        }

        Node * insert(int data, Node * head)
        {
            if(head == NULL)
            {
                Node * b = new Node(data);

                head = b;
            }
            else if(data < head->data)
            {
                head->left = insert(data, head->left);
            }
            else if(data > head->data)
            {
                head->right = insert(data, head->right);
            }
            return head;
        }

        int getsize(Node *& root)
        {
            if(root == NULL)
            {
                return 0;
            }
            
            int leftsum = getsize(root->left);
            int rightsum = getsize(root->right);

            return 1 + leftsum + rightsum;
        }

        int * BSTtoHeap(Node *& root)
        {
            int * array = new int[getsize(root)];

            int index = 0;

            queue <Node*> Q;

            if(root != NULL)
            {
                Q.push(root);

                while(!Q.empty())
                {
                    Node * temp = Q.front();

                    Q.pop();

                    array[index] = temp->data;

                    index++;

                    if(temp->left != NULL)
                    {
                        Q.push(temp->left);
                    }

                    if(temp->right != NULL)
                    {
                        Q.push(temp->right);
                    }
                }
            }

            return array;
        }

        void heapcorrection(int * arr, int size, int index)
        {
            int leftchild = (index * 2) + 1;

            int rightchild = (index * 2) + 2;

            int largest = index;

            if(leftchild < size && arr[leftchild] > arr[largest])
            {
                swap(arr[leftchild], arr[largest]);
            }

            if(rightchild < size && arr[rightchild] > arr[largest])
            {
                swap(arr[rightchild], arr[largest]);
            }

            if(index < size)
            {
                heapcorrection(arr, size, index + 1);
            }
        }

        
};

void printing(int * array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}

int main()
{
    BST * b = new BST();

    b->root = b->insert(5, b->root);
    b->root = b->insert(2, b->root);
    b->root = b->insert(1, b->root);
    b->root = b->insert(4, b->root);
    b->root = b->insert(3, b->root);

    int * arr = new int[b->getsize(b->root)];

    printing(b->BSTtoHeap(b->root), b->getsize(b->root));

    cout << endl;

    arr = b->BSTtoHeap(b->root);

    b->heapcorrection(arr, b->getsize(b->root), 0);

    printing(arr, b->getsize(b->root));
}