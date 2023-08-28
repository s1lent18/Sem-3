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

        // hare and tortoise alogrithm
        
        bool detectcycle(Node * & head)
        {
            Node * rabbit = head;

            Node * tortoise = head;

            while (rabbit != NULL && rabbit->link != NULL)
            {
                tortoise = tortoise->link;

                rabbit = rabbit->link->link;

                if (rabbit == tortoise)
                {
                    return true;
                }
                
            }
            return false;
            
        }

        // Floyd's Aligorithm

        void removalofcycle(Node * & head)
        {
            Node * rabbit = head;

            Node * tortoise = head;

            do
            {
                tortoise = tortoise->link;

                rabbit = rabbit->link->link;

            } while (tortoise != rabbit);

            rabbit = head;

            while (tortoise->link != rabbit->link)
            {
                rabbit = rabbit->link;

                tortoise = tortoise->link;
            }
            
            tortoise->link = NULL;
            
        }
};