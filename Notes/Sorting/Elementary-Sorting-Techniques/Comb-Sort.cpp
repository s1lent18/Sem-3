#include <iostream>
using namespace std;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;

    if(gap < 1)
    {
        return 1;
    }
    return gap;
}

void combsort(int * ptr, int size)
{
    int gap = size;

    bool swapped = true;

    while(gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);

        swapped = false;

        for(int i = 0; i < size - gap; i++)
        {
            if(ptr[i] > ptr[i + gap])
            {
                swap(ptr[i], ptr[i + gap]);

                swapped = true;
            }
        }
    }
}

void print(int * ptr, int size)
{
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

    combsort(ptr, size);

    print(ptr, size);
}