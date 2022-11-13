#include <bits/stdc++.h>
using namespace std;

int board[10][10];
bool isPossible(int n, int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n, int row)
{
    if (n == row)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }           
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isPossible(n, row, col))
        {
            board[row][col] = 1;
            nQueenHelper(n, row + 1);
            board[row][col] = 0;
        }
    }
    return;
}
void printNqueen(int n)
{
    board[10][10] = {0};
    nQueenHelper(n, 0);
}
int main()
{
    int n;
    cin>>n;
    printNqueen(n);
    return 0;
}