#include <iostream>
using namespace std;

bool search(char ** board, int row, int col, int rowsize, int colsize, string word, int index)
{
    if(index == word.size())
    {
        return true;
    }
    
    if(row < 0 || col < 0 || row == rowsize || col == colsize || board[row][col] != word[index])
    {
        return false;
    }

    char character = board[row][col];
    board[row][col] = '#';
    bool option1 = search(board, row + 1, col, rowsize, colsize, word, index + 1);
    bool option2 = search(board, row, col + 1, rowsize, colsize, word, index + 1);
    bool option3 = search(board, row - 1, col, rowsize, colsize, word, index + 1);
    bool option4 = search(board, row, col - 1, rowsize, colsize, word, index + 1);
    board[row][col] = character;
    return option1 || option2 || option3 || option4;
}

bool present(char ** board, string word, int rowsize, int colsize)
{
    for(int row = 0; row < rowsize; row++)
    {
        for(int col = 0; col < colsize; col++)
        {
            if(search(board, row, col, rowsize, colsize, word, 0))
            {
                return true;
            }
        }
    }
    return false;
}
