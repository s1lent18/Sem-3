#include <iostream>
#include <vector>
using namespace std;

// Insert an element from unsorted array to its correct position in sorted array

// Best Case Senario: O(n)
// Average Case Senario: O(n ^ 2)
// Worst Case Senario: O(n ^ 2)

void Insertion(vector <int> vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int current = vec[i], j = i - 1;

        while (vec[j] > current && j >= 0)   // The while loop will iterate 
        {                                    // through the whole array to find
            vec[j + 1] = vec[j];             // the suitable place for the element

            j--; 
        }

        vec[j + 1] = current;
    }

    // Printing

    for (int i = 0; i < vec.size(); i++)
    {
        cout << i + 1 << ": " << vec[i] << endl;
    }
    
}

int main()
{
    vector <int> five = {45, 941, 5, 1, -23};

    Insertion(five);
}