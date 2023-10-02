#include <iostream>
using namespace std;

int LinearSearch(int * arr, int size, int data)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}
