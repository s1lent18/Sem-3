#include <iostream>
using namespace std;
#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

        Node()
        {
            prev = NULL;
            next = NULL;
        }

        Node(int value)
        {
            data = value;
            prev = NULL;
            next = NULL;
        }

};

class LinkedList
{
    public:
        Node * head;

        void insertathead(int value)
        {
            Node * n = new Node(value);

            n->next = head;

            if(head != NULL)
            {
                head->prev = n;
            }

            head = n;
        }

        void insertattail(int value)
        {
            if (head == NULL)
            {
                insertathead(value);

                return;
            }

            Node * n = new Node(value);

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->prev = temp;
        }

        void displayforward()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->next;
            }
        }

        void displaybackwards()
        {
            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            while(temp != head)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->prev;
            }

            cout << "Values: " << temp->data << endl; 
        }

        void deleteathead();
        void deleteattail();
        void deletebyvalue(int value);
        void deleteatindex(int index);
        void insertaftervalue(int after, int value);

};

#endif