#include "Stacks.cpp"

void insertatbottom(Stack <int> & S, int element)
{
    if(S.empty())
    {
        S.push(element);
        return;
    }

    int topelement = S.Top();

    S.pop();

    insertatbottom(S, element);

    S.push(topelement);
}

void reverse(Stack <int> &S)
{
    if(S.empty())
    {
        return;
    }

    int element = S.Top();

    S.pop();

    reverse(S);

    insertatbottom(S, element);
}

int main()
{
    Stack <int> S(5);

    for(int i = 0; i < 5; i++)
    {
        S.push(i);
    }

    reverse(S);

    S.print();
}