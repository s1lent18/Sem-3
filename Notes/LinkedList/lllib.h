#ifndef LLLIB_H_
#define LLLIB_H_

namespace lllib
{
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
                std :: cout << "Value : " << temp ->data << std :: endl;

                temp = temp->link; 
            }
        }

        void deleteathead(Node * &head)
        {
            Node * del = head;

            head = head->link;

            delete del;
        }

        void deletion(Node * & head, int value)
        {
            if (head == NULL)
            {
                return;
            }

            if (head->link == NULL)
            {
                deleteathead(head);

                return;
            }
            
            Node * temp = head;

            while (temp->link->data != value)
            {
                temp = temp->link;
            }

            Node * del = temp->link;

            temp->link = temp->link->link;

            delete del;        
        }

    };
}

#endif