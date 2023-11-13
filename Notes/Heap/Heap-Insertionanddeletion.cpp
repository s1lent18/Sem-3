#include <iostream>
using namespace std;

void heapcorrection(int * arr, int size, int index)
{
    int leftchild = (index * 2) + 1;

    int rightchild = (index * 2) + 2;

    int largest = index;

    if(leftchild < size && arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }

    if(rightchild < size && arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }

    if(largest != index)
    {
        swap(arr[largest], arr[index]);

        heapcorrection(arr, size, index);
    }
}

void deleteroot(int * arr, int size)
{
    int lastinput = arr[size - 1];

    arr[0] = lastinput;

    size--;

    heapcorrection(arr, size, 0);
}

void printing(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}

int main()
{
    int size = 0;

    cin >> size;

    int * array = new int[size];

    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "After Insertion before heaping: ";

    printing(array, size);

    cout << endl;

    for(int i = size; i >= 0; i--)
    {
        heapcorrection(array, size, i);
    }

    cout << "After heaping: " << endl;

    printing(array, size);

    cout << endl;
}