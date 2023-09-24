#include <iostream>
using namespace std;

void printsolution(int ** arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int ** arr, int row, int col, int num)
{
    // to check in column

    for(int i = 0; i <= 8; i++)
    {
        if(arr[i][col] == num)
        {
            return false;
        }
    }

    // to check in row

    for(int i = 0; i <= 8; i++)
    {
        if(arr[row][i] == num)
        {
            return false;
        }
    }

    // to check in box

    int currrow = row - row % 3;
    int currcol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(arr[i + currrow][j + currcol] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoko(int ** arr, int r, int c, int size)
{
    if(r == size - 1 && c == size)
    {
        printsolution(arr, size);

        return true;
    }

    if(c == size)
    {
        r += 1;
        c = 0;
    }

    if(arr[r][c] > 0)
    {
        return sudoko(arr, r, c + 1, size);
    }

    for(int enter = 1; enter <= 9; enter++)
    {
        if(isSafe(arr, r, c, enter))
        {
            arr[r][c] = enter;

            if(sudoko(arr, r, c + 1, size))
            {
                return true;
            }
        }
        arr[r][c] = 0;
    }
    return false;
}

int main()
{
    int temp = 0;

    cout << "enter the size for your sukodo: ";

    cin >> temp;

    int ** array = new int*[temp];

    for(int i = 0; i < temp; i++)
    {
        array[i] = new int[temp];
    }

    for(int i = 0; i < temp; i++)
    {
        for(int j = 0; j < temp; j++)
        {
            cin >> array[i][j];
        }
    }

    printsolution(array, temp);

    cout << endl << endl;

    if(sudoko(array, 0, 0, temp))
    {

    }
    else
    {
        cout << "No Solution exists";
    }
}