/*

9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Ans: true.

3 0 5 4 2 0 8 1 0 
4 8 7 9 0 1 5 0 6 
0 2 9 0 5 6 3 7 4 
8 5 0 7 9 3 0 4 1 
6 1 3 2 0 8 9 5 7 
6 1 3 2 0 8 9 5 7 
0 7 4 0 6 5 2 8 0 
2 4 1 3 0 9 0 6 5 
5 0 8 6 7 0 1 9 2

Ans: false


*/

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