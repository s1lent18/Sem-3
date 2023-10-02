#include <iostream>
using namespace std;

int Interpolation(int * arr,int l, int h, int data)
{
    int pos = 0;

    if(l <= h && data >= arr[l] && data <= arr[h])
    {
        pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (data - arr[l]));

        if(arr[pos] == data)
        {
            return pos;
        }

        if(arr[pos] < data)
        {
            return Interpolation(arr, pos + 1, h, data);
        }

        if(arr[pos] > data)
        {
            return Interpolation(arr, l, pos - 1, data);
        }
    }
    return - 1;
}

int main()
{
    int * arr = new int[5];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    cout << Interpolation(arr, 0, 4, 3);
}