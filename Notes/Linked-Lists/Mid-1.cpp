#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node()
        {

        }

        Node(int data)
        {
            this->data = data;
        }
};

class LinkedList
{
    public:
        Node * head;

        int size(Node * T)
        {
            if(T == NULL)
            {
                return 0;
            }
            else
            {
                return 1 + size(T->next);
            }
        }

        bool find(int data, Node * T)
        {
            if(T == NULL)
            {
                return false;
            }
            else if(T->data == data)
            {
                return true;
            }
            else
            {
                find(data, T->next);
            }
        }

        void printlist(Node * T)
        {
            if(T == NULL)
            {
                return;
            }
            else
            {
                cout << T->data << "->";
                printlist(T->next);
            }
        }

        void insertattaiL(Node *& T, int data)
        {
            if(T == NULL)
            {
                Node * n = new Node(data);

                T = n;
            }
            else
            {
                insertattaiL(T->next, data);
            }
        }

        void reverseprintlist(Node * T)
        {
            if(T == NULL)
            {
                return;
            }
            else
            {
                cout << endl;

                reverseprintlist(T->next);

                cout << T->data << "<-"; 
            }
        }

        Node * reconstruct(Node * T)
        {
            if(T == NULL)
            {
                return T;
            }
            else
            {
                T->next = reconstruct(T->next);

                return T;
            }
        }

        void rescue(int data)
        {
            insertattaiL(head, data);
        }

        void r()
        {
            reverseprintlist(head);
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->rescue(1);
    L->rescue(2);
    L->rescue(3);
    L->rescue(4);
    L->rescue(5);
    L->rescue(6);

    L->r();

}