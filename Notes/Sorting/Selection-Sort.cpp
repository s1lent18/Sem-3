#include <iostream>
#include <vector>
using namespace std;

// Find the minimum element in the unsorted array and swap it with element at beginning

void Selection(vector <int> vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if(vec[j] < vec[i])
            {
                int temp = vec[j];

                vec[j] = vec[i];

                vec[i] = temp;
            }
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