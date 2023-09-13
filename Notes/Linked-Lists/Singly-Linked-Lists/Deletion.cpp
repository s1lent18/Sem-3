#include "Singly-Linked-List.h"

void LinkedList :: deleteathead()
{
    Node * del = head;

    head = head->next;

    delete del;
}

void LinkedList :: deleteattail()
{
    if(head == NULL)
    {
        return;
    }

    if(head->next == NULL)
    {
        deleteathead();

        return;
    }

    Node * temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;

    delete temp->next;
}

void LinkedList :: deletebyvalue(int value)
{
    Node * temp = head;

    if(head == NULL)
    {
        return;
    }   

    if(head->next == NULL)
    {
        deleteathead();

        return;
    }

    while(head->next->data != value)
    {
        temp = temp->next;
    }

    Node * del = temp->next;

    temp->next = temp->next->next;

    delete del;
}

void LinkedList :: deleteatindex(int index)
{
    Node * temp = head;

    if(head == NULL)
    {
        return;
    }

    if(head->next == NULL || (index == 0))
    {
        deleteathead();

        return;
    }

    int count = 0;

    while(temp && count < index - 1)
    {
        temp = temp->next;

        count++;
    }

    if(!temp || !temp->next)
    {
        cout << "Index out of bounds";

        return;
    }

    Node * del = temp->next;

    temp->next = del->next;

    delete del;
    
}
