#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
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

        Node * search(Node * head, int data)
        {
            if(head == NULL)
            {
                return NULL;
            }
            else if(data < head->data)
            {
                return search(head->left, data);
            }
            else if(data > head->data)
            {
                return search(head->right, data);
            }
            else
            {
                return head;
            }
        }

        Node * Min(Node * head)
        {
            if(head == NULL)
            {
                return NULL;
            }
            else if(head->left == NULL)
            {
                return head;
            }
            else
            {
                return Min(head->left);
            }
        }

        Node * Max(Node * head)
        {
            if(head == NULL)
            {
                return NULL;
            }
            else if(head->right == NULL)
            {
                return head;
            }
            else
            {
                return Max(head->right);
            }
        }

        Node * del(int data, Node * head)
        {
            Node * temp;

            if(head == NULL)
            {
                return NULL;
            }
            else if(data < head->data)
            {
                head->left = del(data, head->left);
            }
            else if(data < head->data)
            {
                head->right = del(data, head->right);
            }
            else if(head->left && head->right)
            {
                temp = Min(head->right);
                
                head->data = temp->data;

                head->right = del(head->data, head->right);
            }
            else
            {
                temp = head;

                if(head->left == NULL)
                {
                    head = head->right;
                }
                else if(head->right == NULL)
                {
                    head = head->left;

                    delete temp;
                }
                
                return head;
                
            }
        }
};

int main()
{
    return 0;
}