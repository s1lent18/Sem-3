#include "Doubly-Linked-List.h"

void LinkedList :: merge(LinkedList * T1)
{
    Node * temp = head;

    Node * temp1 = T1->head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = temp1;

    T1->head->prev = temp;
}