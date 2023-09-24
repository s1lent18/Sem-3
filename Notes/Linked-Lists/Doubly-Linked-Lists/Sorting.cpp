#include "Doubly-Linked-List.h"

void LinkedList::sort()
{
    Node* temp = head;
    
    bool flag = false;

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            break;
        }
        else if (temp->data > temp->next->data)
        {
            Node* prev = temp->prev; // Add a previous pointer

            Node* nextNode = temp->next;

            temp->next = nextNode->next;

            if (temp->next != NULL)
            {
                temp->next->prev = temp; // Update the previous pointer of the node after temp
            }

            nextNode->next = temp;

            nextNode->prev = prev; // Update the previous pointer of nextNode

            if (prev == NULL)
            {
                head = nextNode;
            }
            else
            {
                prev->next = nextNode;
            }

            temp->prev = nextNode; // Update the previous pointer of temp
            
            flag = true;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (flag)
    {
        sort();
    }
}

int main()
{
    LinkedList * L = new LinkedList();
    {
        L->insertattail(1);
        L->insertattail(3);
        L->insertattail(2);
        L->insertattail(5);
        L->insertattail(4);

        L->displayforward();

        L->sort();

        L->displayforward();

    }
}