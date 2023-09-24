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

bool inthebounds(int numberofsquares, int row, int col)
{
    if(row >= 0 && row < numberofsquares && col >= 0 && col < numberofsquares)
    {
        return true;
    }
    return false;
}

bool isSafe(int ** arr, int r, int c, int numberofsquares)
{
    if(inthebounds(numberofsquares, r - 2, c - 1))
    {
        if(arr[r - 2][c - 1] == 1)
        {
            return false;
        }
    }

    if(inthebounds(numberofsquares, r - 1, c - 2))
    {
        if(arr[r - 1][c - 2] == 1)
        {
            return false;
        }
    }

    if(inthebounds(numberofsquares, r - 2, c + 1))
    {
        if(arr[r - 2][c + 1] == 1)
        {
            return false;
        }
    }

    if(inthebounds(numberofsquares, r - 1, c + 2))
    {
        if(arr[r - 1][c + 2] == 1)
        {
            return false;
        }
    }

    return true;
}

void nKnights(int ** arr, int numberofknights, int row, int col, int numberofsquares)
{
    if(numberofknights == 0)
    {
        printsolution(arr, numberofsquares);
    }

    if(row == numberofsquares - 1 && col == numberofsquares)
    {
        return;
    }

    if(col == numberofsquares)
    {
        nKnights(arr, numberofknights, row + 1, 0, numberofsquares);

        return;
    }

    if(isSafe(arr, row, col, numberofsquares))
    {
        arr[row][col] = 1;

        nKnights(arr,numberofknights - 1, row, col + 1, numberofsquares);

        arr[row][col] = 0;
    }

    nKnights(arr,numberofknights, row, col + 1, numberofsquares);
}

int main()
{
    cout << "Enter the size of the chess board: ";

    int ans = 0;

    cin >> ans;

    int knights = ans * ans;

    if(knights % 2 == 0)
    {
        knights /= 2;
    }
    else
    {
        knights += 1;

        knights /= 2;
    }

    cout << "The chess board is of: " << ans << " * " << ans << endl << "The number of knights to be placed: " << knights << endl;

    int ** array = new int*[ans];

    for(int i = 0; i < ans; i++)
    {
        array[i] = new int[ans];
    }

    nKnights(array, knights, 0, 0, ans);
    
}