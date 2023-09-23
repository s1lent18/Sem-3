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

            cout << endl;

            while(temp != NULL)
            {
                cout << temp->data << " -> ";

                temp = temp->next;
            }

            cout << "NULL"<< endl << endl;
        }

        void deleteathead();
        void deleteattail();
        void deletebyvalue(int value);
        void deleteatindex(int index);
        void insertaftervalue(int value, int aftervalue);
        void reverseitirative();
        void sort();
        Node * reverserecursive(Node *);

};

#endif