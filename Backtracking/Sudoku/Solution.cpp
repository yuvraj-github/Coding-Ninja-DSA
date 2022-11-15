#include <bits/stdc++.h>
using namespace std;
#define N 9
bool isSafe(int board[N][N], int row, int col, int val)
{
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
        if (board[i][col] == val)
        {
            return false;
        }
        // 3*3 grid check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solveSudoku(int board[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= N; val++)
                {
                    if (isSafe(board, row, col, val))
                    {
                        board[row][col] = val;
                        bool checkNextPossibleSolution = solveSudoku(board);
                        if (checkNextPossibleSolution)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{

    // write your code here
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    bool checksolveSudoku = solveSudoku(board);
    if (checksolveSudoku)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}