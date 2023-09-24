#include "Singly-Linked-List.h"

void LinkedList :: merge(LinkedList * T)
{
    Node * temp = head;

    Node * temp1 = T->head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = temp1;

    display();
}

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(3);
    L->insertattail(4);
    L->insertattail(5);

    LinkedList * T = new LinkedList();

    T->insertattail(6);
    T->insertattail(7);
    T->insertattail(8);
    T->insertattail(9);
    T->insertattail(10);

    L->merge(T);
}