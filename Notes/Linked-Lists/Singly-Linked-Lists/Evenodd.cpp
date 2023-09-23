#include "Singly-Linked-List.h"

void LinkedList :: Evenodd(Node *& temp, Node *&prev, int firstodd, int count)
{
    if(firstodd == temp->data)
    {
        return;
    }

    if(temp->data % 2 != 0)
    {
        if(count == 0)
        {
            firstodd = temp->data;
        }

        count++;

        insertattail(temp->data);

        if(temp == head)
        {
            head = temp->next;
            
            temp = NULL;

            temp = head;

        }
        else
        {
            prev->next = temp->next;

            temp = NULL;

            temp = prev->next;
        }
        display();
    }
    else
    {
        prev = temp;

        temp = temp->next;
    }
    
    Evenodd(temp, prev, firstodd, count);
}

void LinkedList :: run()
{
    Node * temp = head;

    Node * prev = NULL;

    Evenodd(temp, prev, 0, 0);
}