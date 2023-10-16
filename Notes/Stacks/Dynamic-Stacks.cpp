#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node()
        {

        };

        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        void insertathead(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Node * temp = head;

            n->next = temp;

            head = n;

            return;
        }

        void deleteathead()
        {
            Node * del = head;

            head = head->next;

            del = NULL;

            delete del;
        } 

        int last()
        {
            Node * temp = head;

            return temp->data;
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << temp->data << " -> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        } 
};

class Stacks
{
    private:
        LinkedList * L;
        int top;

    public:
        Stacks()
        {
            top = -1;
        }

        void push(int element)
        {
            top += 1;
            
            L->insertathead(element);
        }

        void pop()
        {
            L->deleteathead();

            top -= 1;
        }

        int Top()
        {
            return L->last();
        }

        bool isempty()
        {
            if(L->head == NULL)
            {
                return 1;
            }
            return 0;
        }
};

// int main()
// {
//    Stacks * S = new Stacks();

//    S->push(1);
//    S->push(2);
//    S->push(3);
//    cout << S->Top() << endl;
//    S->pop();
//    cout << S->Top() << endl;
//    S->pop();
//    cout << S->Top() << endl;
//    S->pop();
// }