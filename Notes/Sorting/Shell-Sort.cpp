#include <iostream>
using namespace std;

void shellsort(int * ptr, int size)
{
    for(int gap = size / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; i+= 1)
        {
            int temp = ptr[i];

            int j;

            for(j = i; j >= gap && ptr[j - gap] > temp; j-= gap)
            {
                ptr[j] = ptr[j - gap];
            }

            ptr[j] = temp;
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << ptr[i] << endl;
    }
}

int main()
{
    int size = 0; 

    cout << "Enter size: ";

    cin >> size;

    int * ptr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }

    shellsort(ptr, size);
}