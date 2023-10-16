#include <iostream>
using namespace std;

template <class T>

class Queue
{
    private:
        T * arr;
        int front;
        int back;
        int size;

    public:
        Queue(int size)
        {
            arr = new int[size];
            front = -1;
            back = -1;
        }

        void push(T element)
        {
            if(back == size - 1)
            {
                cout << " Queue OverFlow " << endl;

                return;
            }

            back += 1;

            arr[back] = element;

            if(front == -1)
            {
                front++;
            }
        }   

        void pop()
        {
            if(front == -1 || front > back)
            {
                cout << " Queue Empty " << endl;

                return;
            }

            front += 1;
        }

        T peek()
        {
            if(front == -1 || front > back)
            {
                cout << " Queue Empty " << endl;

                return -1;
            }

            return arr[front];
        }

        bool isempty()
        {
            if(front == -1 || front > back)
            {
                return 1;
            }
            return 0;
        }

        
};

int main()
{
    Queue <int> Q(5);

    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    cout << Q.peek() << endl;

    Q.pop();

    cout << Q.peek() << endl;

    Q.pop();

    cout << Q.peek() << endl;

    Q.pop();

    cout << Q.peek() << endl;

    Q.pop();

    cout << Q.peek() << endl;

    Q.pop();

    cout << Q.isempty() << endl;
}