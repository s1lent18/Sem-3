#include <iostream>
using namespace std;

// Best and average time case: O(n*log(n))
// Worst Time Case: O(n^2)

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[right]);

    return i + 1;
}

void QuickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(arr, left, right);

        QuickSort(arr, left, pivot - 1);

        QuickSort(arr, pivot + 1, right);
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}