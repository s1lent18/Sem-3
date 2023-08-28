#include <iostream>
#include <vector>
using namespace std;


// The idea of bubble sorting is reapetedly swapping two adjacent elements if
// they are in a wrong order

// For an array of n elements we have to do n - 1 iterations before we get a sorted array

// for ith iteration we will check till n - i position

// the reason to call it bubble sort is the smallest element rises to the beginning of the array
// while the larger elements sink to the end of the array

void bubblesort(vector <int> vec)
{
    int count = 1;

    while (count < vec.size())
    {
        for (int i = 0; i < (vec.size() - count); i++)
        {
            if (vec[i] > vec[i + 1])    // checking whether the element on the left is greater than the element on the right
            {
                int temp = vec[i];      // if the condition passes then we swap these two elements

                vec[i] = vec[i + 1];

                vec[i + 1] = temp;
            }
            
        }
        count++;
    }

    // printing

    for (int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " << vec[i] << endl;
    }
    
    
}

int main()
{
    vector <int> vec = {4, 9, 15, 1, 3};

    bubblesort(vec);
}