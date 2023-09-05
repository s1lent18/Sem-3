#include <iostream>
using namespace std;

bool sorted(int arr[], int size)
{
    if(size == 1)
    {
        return true;
    }

    bool restarr = sorted(arr + 1, size - 1);
    
    return (arr[0] < arr[1] && restarr);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << sorted(arr, 5) << endl;
}