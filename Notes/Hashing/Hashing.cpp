#include <iostream>
using namespace std;

class Node
{
    public:
        string name;
        int age;;
        Node * next;                          // For Chaining

        Node()
        {

        };

        Node(string name, int age)
        {
            this->name = name;
            this->age = age;
            next = NULL;
        }
};

class HashTable
{
    private:
        Node ** Table;
        int size;
        int count;           // For Linear Probing

    public:
        HashTable()
        {
            Table = new Node* [10];
            size = 10;
            count = 0;
        }

        HashTable(int size)
        {
            Table = new Node * [size];

            this->size = size;
        }

        int HashFormula(string name)
        {
            return (name[0] % 65);
        }

        int QuadLinearProbe(int index)
        {
            int i = 1;

            int og = index;

            while(Table[index] != NULL)
            {
                index = (og + i * i) % size;
                i++;
            }

            return index;
        }

        int LinearProbe(int index)
        {
            int i = 1;

            while(Table[index] != NULL)
            {
                index = (index + i) % size;
                i++;
            }
            return index;
        }

        void InsertChaining(string name, int age)          // Through Chaining
        {
            Node * n = new Node(name, age);

            int index = HashFormula(name);

            if(Table[index] == NULL)
            {
                Table[index] = n;
            }
            else
            {
                Node * temp = Table[index];

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = n;
            }
        }

        void InsertProbing(string name, int age)
        {
            if(count == size)
            {
                cout << "Please Resize the hash-Table" << endl;

                return;
            }

            Node * n = new Node(name, age);

            int index = HashFormula(name);

            if(Table[index] == NULL)
            {
                Table[index] = n;
            }
            else
            {
                index = LinearProbe(index);

                Table[index] = n;
            }

            count++;
        }
};