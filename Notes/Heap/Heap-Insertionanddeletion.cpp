#include <iostream>
using namespace std;

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

void printing(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}

void heapcorrection(int * arr, int size, int index)
{
    int leftchild = (index * 2) + 1;                             // 1

    int rightchild = (index * 2) + 2;                            // 2

    int largest = index;                                         // 0

    if(leftchild < size && arr[leftchild] > arr[largest])        // 1 < 10 && 2 > 1
    {
        largest = leftchild;
    }
    else if(rightchild < size && arr[rightchild] > arr[largest])
    {
        largest = rightchild; 
    }

    if(largest != index)
    {
        swap(arr[index], arr[largest]);
    }

    heapcorrection(arr, size, largest);
}

int deleteroot(int * arr, int size)
{
    int lastinput = arr[size - 1];

    arr[0] = lastinput;

    size--;

    heapcorrection(arr, size, 0);

    return size;
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

    heapcorrection(array, size, 0);

    cout << "After heaping: " << endl;

    printing(array, size);

    cout << endl;
}