#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * link;

    Node(int value)                                    // Constructor
    {
        data = value;
        link = NULL;
    }

    void insertathead(Node * & head, int value)        // Taking the linked list [by reference] and the value to be inserted as arguments
    {
        Node * n = new Node(value);

        n->link = head;

        head = n;
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

    void display(Node * head)                          // taking linked list [by value and not by reference since there are no modifications to be made]
    {
        Node * temp = head;

        while(temp != NULL)                            // loop will run till the end of list
        {
            cout << "Value : " << temp ->data << endl;

            temp = temp->link; 
        }
    }

};