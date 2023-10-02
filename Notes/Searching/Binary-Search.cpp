#include <iostream>
using namespace std;

int BinarySearch(int * arr, int size, int data)
{
    int l = 0, h = size - 1;

    while(l <= h)
    {
        int c = l + (h - 1) / 2;

        if(arr[c] == data)
        {
            return c;
        }
        else if(arr[c] > data)
        {
            h = c - 1;
        }
        else if(arr[c] < data)
        {
            l = c + 1;
        }
    }
    return - 1;
}