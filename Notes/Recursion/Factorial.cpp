#include <iostream>
using namespace std;

int Factorial(int number)
{
    if(number == 1)
    {
        return 1;
    }

    int prevfac = Factorial(number - 1);

    return number * prevfac;
}

int main()
{
    cout << Factorial(5) << endl;
}