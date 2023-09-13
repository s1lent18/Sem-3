#include "Singly-Linked-List.h"

void LinkedList :: reverseitirative()
{
    Node * prev = NULL;
    Node * curr = head;
    Node * Next;

    while(curr != NULL)
    {
        Next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = Next;
    }

    head = prev;
}

Node * LinkedList :: reverserecursive(Node * Head)
{
    if(Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node * temp = reverserecursive(Head->next);

    Head->next->next = head;

    head->next = NULL;

    return temp;
}

