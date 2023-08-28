#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * link;

        Node(int value)
        {
            data = value;
        }

        void display(Node * head)                          // taking linked list [by value and not by reference since there are no modifications to be made]
        {
            Node * temp = head;

            while(temp != NULL)                            // loop will run till the end of list
            {
                cout << "Value : " << temp ->data << endl;

                temp = temp->link; 
            }
        }

        void insertattail(Node * & head, int value)        // Taking the linked list [by reference] and the value to be inserted as arguments
        {
            Node * n = new Node(value);
            
            if (head == NULL)                              // if there is nothing in the linked list then it is run
            {
                head = n;

                return;
            }
            
            Node * temp = head;                           

            while(temp->link != NULL)                      // Traversing to the end of the list
            {
                temp = temp->link;
            }

            temp->link = n;                                // linking n to the last of the linked last the link of n is already set to null
        }

};

Node * reverseitirative(Node * & head)
{
    Node * previous = NULL;                                // setting up 3 pointers as prev, curr and next which will work as bubble sorting 

    Node * current = head;                                 // initializing prev as NULL, curr as head.

    Node * next;

    while (current != NULL)                                // running a while loop with the condition that the loop will run until curr is not reaching the last node of the list
    {
        next = current->link;                              // next is now iniliazied as the link of current which will help us itirate through the linked list

        current->link = previous;                          // changing the current pointer from next to previous i.e reversing the linked list

        previous = current;                                // updating the positions of curr to next and prev to current

        current = next;
    }

    return previous;                                       // returning prev i.e the head of the reversed linked list 
}

Node * reverserecursive(Node * & head)
{
    if(head == NULL || head->link == NULL)                 // exception case if the linked list has no nodes or just a single node
    {
        return head;
    }
    
    Node * newhead = reverserecursive(head->link);

    head->link->link = head;                               // reversing of the linked list 

    head->link = NULL;                                     // head now changed to last node

    return newhead;
}

Node * reversek(Node * & head, int k)
{
    Node * prev = NULL;

    Node * curr = head;

    Node * next;

    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->link;

        curr->link = prev;

        prev = curr;

        curr = next;

        count++;
    }

    if(next != NULL)
    {
        head->link = reversek(next, k);
    }

    return prev;
    
}
// ---------------------------------------- Time Complexity: O(n) ----------------------------------------


int main()
{
    Node * Head = NULL;

    Head->insertattail(Head, 4);
    Head->insertattail(Head, 3);
    Head->insertattail(Head, 2);
    Head->insertattail(Head, 1);

    Node * hash = reverserecursive(Head);
    
    Head->display(hash);
    
    Node * newhead = reversek(hash, 3);

    Head->display(newhead);

}