#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Stack
{
    public:
        int * data;
        int top;
        int size;

        Stack()
        {
            data = new int[100];
            size = 100;
            top = -1;
        }

        void push(int val)
        {
            if(top == size - 1)
            {
                cout << "Stack OverFlow" << endl;

                return;
            }

            top += 1;
            data[top] = val;
        }

        void pop()
        {
            if(top == -1)
            {
                cout << "Stack Empty" << endl;

                return;
            }

            top--;
        }

        bool isempty()
        {
            return top == -1;
        }

        int Top()
        {
            if(!isempty())
            {
                return data[top];
            }
        }
};

class Players
{
    public:
        int * result;
        int current;

        Players()
        {
            result = new int[25];
        }

        int Total()
        {
            int total = 0;

            for(int i = 0; i < 25; i++)
            {
                total += result[i];
            }

            return total;
        }

        void Add(int index)
        {
            result[index] = 4;
        }

        void add(int index)
        {
            result[index] = 0;
        }

};

Stack PileFill()
{
    srand(time(0));

    int array[100];

    Stack S;

    int temp = rand() % 101; 

    S.push(temp);

    array[0] = temp;

    for(int i = 1; i < 100; i++)
    {
        again:
            temp = rand() % 101;

            for(int j = 0; j < i; j++)
            {
                if(array[j] == temp)
                {
                    goto again;
                }
            }

            S.push(temp);

            array[i] = temp;
    }

    return S;
}

int main()
{
    Stack s = PileFill();

    Players P1;
    Players P2;
    Players P3;
    Players P4;

    for(int i = 0; i < 25; i++)
    {
        P1.current = s.Top();
        s.pop();
        P2.current = s.Top();
        s.pop();
        P3.current = s.Top();
        s.pop();
        P4.current = s.Top();
        s.pop();

        int max = P1.current;

        if(P2.current > max)
        {
            max = P2.current;
        }
        if(P3.current > max)
        {
            max = P3.current;
        }
        if(P4.current > max)
        {
            max = P4.current;
        }

        if(max == P1.current)
        {
            P1.Add(i);
            P2.add(i);
            P3.add(i);
            P4.add(i);
        }
        else if (max == P2.current)
        {
            P1.add(i);
            P2.Add(i);
            P3.add(i);
            P4.add(i);
        }
        else if (max == P3.current)
        {
            P1.add(i);
            P2.add(i);
            P3.Add(i);
            P4.add(i);
        }
        else if (max == P4.current)
        {
            P1.add(i);
            P2.add(i);
            P3.add(i);
            P4.Add(i);
        }
        

    }

    int max = P1.Total();
    string ans = "Player 1";

    if(P2.Total() > max)
    {
        max = P2.Total();
        ans = "Player 2";
    }
    if(P3.Total() > max)
    {
        max = P3.Total();
        ans = "Player 3";
    }
    if(P4.Total() > max)
    {
        max = P4.Total();
        ans = "Player 4";
    }

    cout << ans << " Won with " << max << " Number of cards in his pile" << endl; 
}