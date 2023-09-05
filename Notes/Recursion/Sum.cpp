#include <iostream>
using namespace std;

int sum(int number)
{
    if(number == 0)
    {
        return 0;
    }

    int prevSum = sum(number - 1);

    return number + prevSum;
}

int main()
{
    cout << sum(5) << endl;
}