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

void LinkedList :: deleteatindex(int index)
{
    Node * temp = head;

    int count = 0;

    if(index == 0)
    {
        deleteathead();
    }

    while(temp->next != NULL)
    {
        if(count == index)
        {
            Node * del = temp;

            temp->prev->next = temp->next;

            temp->next->prev = temp->prev;

            delete del;
        }
        temp = temp->next;

        count++;
    }
}

void LinkedList :: deletebyvalue(int value)
{
    if(head->data == value)
    {
        deleteathead();
    }

    Node * temp = head;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            Node * del = temp;

            temp->prev->next = temp->next;

            temp->next->prev = temp->prev;

            delete del;
        }
        temp = temp->next;
    }
}
