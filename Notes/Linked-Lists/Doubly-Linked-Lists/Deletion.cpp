#include "Doubly-Linked-List.h"

void LinkedList :: deleteathead()
{
    if(head == NULL)
    {
        return;
    }

    Node * temp = head;

    if(head->next != NULL)
    {
        head->next->prev = NULL;
    }

    head = head->next;

    temp->next = NULL;

    delete temp;
}

void LinkedList :: deleteattail()
{
    if(head == NULL)
    {
        return;
    }

    if(head->next == NULL)
    {
        head = NULL;

        delete head;

        return;
    }

    Node * temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node * del = temp->next;

    temp->next = NULL;

    delete del;
}

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(2);
    T->insertattail(3);
    T->insertattail(4);
    T->insertattail(5);

    T->displayforward();

    T->deleteattail();

    T->displayforward();
}