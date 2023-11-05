#include <iostream>
using namespace std;

int partition(int * arr, int left, int right)
{
    int p = arr[right];

    int i = left - 1;

    for(int j = left; j <= right; j++)
    {
        if(arr[j] < p)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[right]);

    return i + 1;
}

void QuickSort(int * arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);

        QuickSort(arr, l, pivot - 1);

        QuickSort(arr, pivot + 1, r);
    }
}

void print(int * arr, int size)
{
    cout << endl;

    for(int i = 1; i <= size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int * arr = new int[6];

    for(int i = 1; i <= 5; i++)
    {
        cin >> arr[i];
    }

    print(arr, 5);

    QuickSort(arr, 1, 6);

    print(arr, 5);
}