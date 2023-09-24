#include <iostream>
using namespace std;

void printsolution(int ** arr, int numberofsquares)
{
    for(int i = 0; i < numberofsquares; i++)
    {
        for(int j = 0; j < numberofsquares; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int ** arr, int row, int col, int numberofsquares)
{
    // checking the horizontal row
    
    for(int r = 0; r < row; r++)
    {
        if(arr[r][col] == 1)
        {
            return false;
        }
    }

    // checking the top left diagongal

    int r = row;
    int c = col;

    while(r >= 0 && c >= 0)
    {
        if(arr[r][c] == 1)
        {
            return false;
        }
        r -= 1;
        c -= 1;
    }

    r = row;
    c = col;

    while(r >= 0 && c < numberofsquares)
    {
        if(arr[r][c] == 1)
        {
            return false;
        }
        r -= 1;
        c += 1;
    }

    return true;
}

bool nQueens(int ** arr, int numberofqueens, int numberofsquares)
{
    if(numberofqueens == numberofsquares)
    {
        printsolution(arr, numberofqueens);

        return true;
    }

    for(int col = 0; col < numberofsquares; col++)
    {
        if(isSafe(arr, numberofqueens, col, numberofsquares))
        {
            arr[numberofqueens][col] = 1;

            nQueens(arr, numberofqueens + 1, numberofsquares);

            arr[numberofqueens][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 0;

    cout << "Enter the size of the board: ";

    cin >> n;

    int ** array = new int * [n];

    for(int i = 0; i < n; i++)
    {
        array[i] = new int[n];
    }

    nQueens(array, 0, n);

}