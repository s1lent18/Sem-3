#include "Singly-Linked-List.h"

void LinkedList :: sort()
{
    Node * next = NULL;

    Node * temp = head;

    bool flag = false;

    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            break;
        }
        else if(temp->data > temp->next->data)
        {
            Node * prev = temp->next;

            temp->next = prev->next;

            prev->next = temp;

            if(next == NULL)
            {
                head = prev;
            }
            else
            {
                next->next = prev;
            }
            flag = true;
        }
        next = temp;

        temp = temp->next;
    }
    if(flag)
    {
        sort();
    }
}
