#include <iostream>
using namespace std;

int returnMax(int * arr, int size)
{
    int max = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int * arr, int size, int exp)
{   
    int * output = new int[size];

    int count[10] = {0};

    for(int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10];
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];

        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void RadixSort(int * arr, int size)
{
    int max = returnMax(arr, size);

    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, size, exp);
    }
}
