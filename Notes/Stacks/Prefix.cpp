#include "Stacks.cpp"
#include <cmath>
int prefix(string input)
{
    Stack <int> S(input.length());

    for(int i = input.length() - 1; i >= 0; i--)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            S.push(input[i] - '0');
        }
        else
        {
            int op1 = S.Top();
            S.pop();

            int op2 = S.Top();
            S.pop();

            switch (input[i])
            {
            case '+':
                S.push(op1 + op2);
                break;
            
            case '-':
                S.push(op1 - op2);
                break;

            case '*':
                S.push(op1 * op2);
                break;

            case '/':
                S.push(op1 / op2);
                break;

            case '^':
                S.push(pow(op1, op2));
                break;

            default:
                break;
            }
        }
    }

    return S.Top();
}

int main()
{
    cout << prefix("-+7*45+20") << endl;

    return 0;
}