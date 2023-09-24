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

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(2);
    T->insertattail(3);
    T->insertattail(4);
    T->insertattail(5);

    LinkedList * T1 = new LinkedList();

    T1->insertattail(6);
    T1->insertattail(7);
    T1->insertattail(8);
    T1->insertattail(9);
    T1->insertattail(10);

    T->merge(T1);

    T->displayforward();

    T->displaybackwards();

}