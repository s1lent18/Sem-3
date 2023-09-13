#include "Singly-Linked-List.h"

void LinkedList :: getsize()
{
    Node * temp = head;

    int count = 0;

    while(temp != NULL)
    {
        count += 1;

        temp = temp->next;
    }

    size = count;
}

Node * LinkedList ::swap(Node * ptr1, Node * ptr2)
{
    Node * temp = ptr2->next;

    ptr2->next = ptr1->next;

    ptr1->next = temp;

    return ptr2;
}

void LinkedList :: bubblesort()
{
    for(int i = 0; i <= size; i++)
    {
        Node * temp = head;

        int swapped = 0;

        Node * ptr1 = temp;

        Node * ptr2 = ptr1->next;

        for(int j = 0; j < size - i; j++)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = swap(ptr1, ptr2);

                swapped = 1;
            }
            temp = temp->next;
        }

        if(swapped == 0)
        {
            break;
        }
    }
}
