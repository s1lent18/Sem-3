#include <iostream>
using namespace std;

template <class T>

class Stack
{
    private:
        T * arr;
        int top;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            arr = new T[size];
            top = -1;
        }

        void push(T element)
        {
            if(top == size - 1)
            {
                cout << "Stack OverFlow " << endl;

                return;
            }

            top += 1;
            arr[top] = element;
        }

        void pop()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return;  
            }

            top -= 1;
        }

        T Top()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return -1;
            }

            return arr[top];
        }

        bool empty()
        {
            return top == -1;
        }


};

int main()
{
    string input;

    cout << "Enter a string: " ;

    cin >> input;

    Stack <char> S(input.length());

    for(int i = 0; i < input.length(); i++)
    {
        S.push(input[i]);
    }

    for(int i = 0; i < input.length(); i++)
    {
        cout << S.Top();
        S.pop();
    }

    
}