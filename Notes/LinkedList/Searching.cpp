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

    bool search(Node * & head, int key)                // passing the node [by reference] and then a key to check 
    {
        Node * temp = head;

        while (temp !=  NULL)                          // loop running till the last node
        {
            if(temp->data == key)                               
            {
                return true;
            }

            temp = temp->link;
        }

        return false;
        
    }
};