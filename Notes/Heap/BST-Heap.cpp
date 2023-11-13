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

        void fillArr(Node *& root, Node ** array, int  index) 
        {
            if (root != NULL) 
            {
                fillArr(root->left, array, index);

                array[index++] = root;

                fillArr(root->right, array, index);
            }
        }

        Node ** inorder(Node *& root)
        {
            Node ** arr = new Node*[getsize(root)];

            fillArr(root, arr, 0);

            return arr;
        } 

        Node * toCBT(Node *& root)
        {
            if(root != NULL)
            {
                Node ** array = new Node*[getsize(root)];

                array = inorder(root);

                for(int i = 0; i < getsize(root); ++i)
                {
                    if (2 * i + 1 < getsize(root)) 
                    {
                        array[i]->left = array[2 * i + 1];
                    } 
                    else 
                    {
                        array[i]->left = NULL;
                    }

                    if (2 * i + 2 < getsize(root)) 
                    {
                        array[i]->right = array[2 * i + 2];
                    } 
                    else 
                    {
                        array[i]->right = NULL;
                    }
                }
                return array[0];
            }
        }

        void fill2(Node *& root, int * array, int index)
        {
            if (root != NULL) 
            {
                fill2(root->left, array, index);

                array[index++] = root->data;

                fill2(root->right, array, index);
            }
        }

        int * fill(Node *& root)
        {
            int * arr = new int[getsize(root)];

            fill2(root, arr, 0);

            return arr;
        }

        void heapify(int * arr, int size, int i) 
        {
            int largest = i;
            int left_child = 2 * i + 1;
            int right_child = 2 * i + 2;

            if (left_child < size && arr[left_child] > arr[largest]) 
            {
                largest = left_child;
            }

            if (right_child < size && arr[right_child] > arr[largest]) 
            {
                largest = right_child;
            }

            if (largest != i) 
            {
                swap(arr[i], arr[largest]);
                heapify(arr, size, largest);
            }
        }

        void convertToHeap(int * arr, int size) 
        {
            for (int i = size / 2 - 1; i >= 0; --i) 
            {
                heapify(arr, size, i);
            }

        }

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

    b->insert()
}