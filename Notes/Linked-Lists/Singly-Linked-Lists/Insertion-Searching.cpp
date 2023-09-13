#include "Singly-Linked-List.h"

void LinkedList :: insertaftervalue(int value, int aftervalue)
{
    Node * n = new Node(value);

    if(head == NULL)
    {
        head = n;
    }

    Node * temp = head;

    while(temp->next != NULL)
    {
        if(temp->data == aftervalue)
        {
            n->next = temp->next;

            temp->next = n;

            return;
        }
        temp = temp->next;
    }
}