#include <iostream>
#include <vector>
using namespace std;

// Find the minimum element in the unsorted array and swap it with element at beginning

void Selection(vector <int> vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int minindex = i;

        for (int j = i + 1; j < vec.size(); j++)
        {
            if(vec[j] < vec[minindex])
            {
                minindex = j;
            }
        }

        if(minindex != i)
        {
            int temp = vec[minindex];

            vec[minindex] = vec[i];

            vec[i] = temp;
        }
        
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << i + 1 << ": " << vec[i] << endl;
    }
    
    
}

int main()
{
    vector <int> vec = {43, 2, 67, 10, 101};

    Selection(vec);
}