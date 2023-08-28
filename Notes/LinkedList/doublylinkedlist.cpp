#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

        Node(int value)
        {
            data = value;
            prev =NULL;
            next = NULL;
        }

        void insertathead(Node * & head, int value)
        {
            Node * n = new Node(value);

            n->next = head;

            if (head != NULL)
            {
                head->prev = n;
            }

            head = n;
        }

        void insertattail(Node * & head, int value)
        {
            if(head == NULL)
            {
                insertathead(head, value);
            }

            Node * n = new Node(value);

            Node * temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            
            temp->next = n;

            n->prev = temp;
        }

        void deleteathead(Node * & head)
        {
            Node * todelete = head;

            head = head->next;

            head->prev = NULL;

            delete todelete;
        }

        void deletion(Node * & head, int pos)
        {
            if (pos == 1)
            {
                deleteathead(head);  

                return;
            }
            
            
            Node * temp;

            int count = 1;

            while (temp != NULL && count != pos)
            {
                temp = temp->next;

                count++;
            }

            temp->prev->next = temp->next;

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            
            delete temp;
            
        }
};