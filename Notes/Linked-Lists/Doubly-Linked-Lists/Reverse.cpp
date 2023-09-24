#include "Doubly-Linked-List.h"

void LinkedList :: reverserecursive(Node * temp)
{
    if(temp == NULL)
    {
        return;
    }

    Node * T = temp->prev;

    temp->prev = temp->next;

    temp->next = T;

    head = temp;

    if(temp->prev == NULL)
    {
        return;
    }
    reverserecursive(temp->prev);
}

void LinkedList ::reverse()
{
    reverserecursive(head);
}

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(3);
    L->insertattail(4);
    L->insertattail(5);

    L->displayforward();

    L->reverse();

    L->displayforward();
}