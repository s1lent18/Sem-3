#include <iostream>
using namespace std;
#ifndef SinglyLinkedList_H
#define SinglyLinkedList_H

class Node
{
    public:
        int data;
        Node * next;

        Node()
        {

        };

        Node(int value)
        {
            data = value;
            next = NULL;
        } 
};

class LinkedList
{
    public:
        Node * head;
        int size;
        
        LinkedList()
        {
            head = NULL;
        };

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            temp = n;
        }

        void insertathead(int value)
        {
            Node * n = new Node(value);

            n->next = head;

            head = n;
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->next;
            }

            cout << endl << endl;
        }

        void deleteathead();
        void deleteattail();
        void deletebyvalue(int value);
        void deleteatindex(int index);
        void insertaftervalue(int value, int aftervalue);
        Node * swap(Node *, Node *);
        void getsize();
        void bubblesort();
        void reverseitirative();
        Node * reverserecursive(Node *);


};

#endif