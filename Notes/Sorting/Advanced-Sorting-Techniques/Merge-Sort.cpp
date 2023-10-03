#include <iostream>
using namespace std;

void merge(int * arr, int l, int c, int h)
{
    int size1 = c - l + 1;
    int size2 = h - c;

    int * arr1 = new int[size1];
    int * arr2 = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        arr1[i] = arr[l + i];
    }

    for(int i = 0; i < size2; i++)
    {
        arr2[i] = arr[c + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesort(int * arr, int l, int h)
{
    if(l < h)
    {
        int c = l + (h - l) / 2;

        mergesort(arr, l, c);
        mergesort(arr, c + 1, h);

        merge(arr, l, c, h);
    }
}