#include "Stacks.cpp"
#include <cmath>
using namespace std;

int postfix(string input)
{
    Stack <int> S(input.length());

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            S.push(input[i] - '0');
        }
        else
        {
            int op2 = S.Top();
            S.pop();

            int op1 = S.Top();
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
}