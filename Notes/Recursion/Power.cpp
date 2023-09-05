#include <iostream>
using namespace std;

int Power(int number, int p)
{
    if(p == 0)
    {
        return 1;
    }

    int prevpower = Power(number, p - 1);

    return number * prevpower;

}

int main()
{
    cout << Power(2, 3) << endl;
}