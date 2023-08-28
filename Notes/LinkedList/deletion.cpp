#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node * link;

    Node(int value)
    {
        data = value;
        link = NULL;
    }

    void deleteathead(Node * &head)
    {
        Node * del = head;

        head = head->link;

        delete del;
    }

    void deletion(Node * & head, int value)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->link == NULL)
        {
            deleteathead(head);

            return;
        }
        
        Node * temp = head;

        while (temp->link->data != value)
        {
            temp = temp->link;
        }

        Node * del = temp->link;

        temp->link = temp->link->link;

        delete del;        
    }

};

