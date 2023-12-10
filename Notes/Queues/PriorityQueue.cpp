#include <iostream>
#include <vector>
using namespace std;

template <class T>

class PQ
{
    private:
        vector <T> data;

        void heapifyup()
        {
            int index = data.size() - 1;

            while(index > 0)
            {
                int parentindex = (index - 1) / 2;

                if(data[index] < data[parentindex])
                {
                    swap(data[index], data[parentindex]);

                    index = parentindex;
                }
                else
                {
                    break;
                }
            }
        }

        void heapifydown()
        {
            int index = 0;

            while(1)
            {
                int leftchild = index * 2 + 1;
                int rightchild = index * 2 + 1;

                int smallest = index;

                if (leftChild < data.size() && data[leftChild] < data[smallest]) 
                {
                    smallest = leftChild;
                }

                if (rightChild < data.size() && data[rightChild] < data[smallest]) 
                {
                    smallest = rightChild;
                }

                if (smallest != index) 
                {
                    swap(data[index], data[smallest]);

                    index = smallest;

                } else 
                {
                    break;
                }
            }
        }
    public:

        void push(T& value)
        {
            data.push_back(value);

            heapifyup();
        }      

        T pop()
        {
            if(empty())
            {
                cout << "Empty" << endl;
            }

            T top = data[0];

            data[0] = data.back();

            data.pop_back();

            heapifydown();

            return top;
        }
        
        bool empty()
        {
            return data.empty();
        }
};