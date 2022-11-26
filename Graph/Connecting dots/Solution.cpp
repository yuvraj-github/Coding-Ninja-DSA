#include <iostream>
#include <vector>
using namespace std;

int l = 0;
void hasCycleHelper(vector<vector<char>> &board, int n, int m, int i, int j, char c, int t, int **d)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    if (board[i][j] != c)
        return;

    if (d[i][j] != 0)
    {
        if (d[i][j] - t + 1 >= 4)
            l++;
        return;
    }
    if (l > 0)
        return;
    t++;
    d[i][j] = t;
    hasCycleHelper(board, n, m, i + 1, j, c, t, d);
    hasCycleHelper(board, n, m, i, j + 1, c, t, d);
    hasCycleHelper(board, n, m, i - 1, j, c, t, d);
    hasCycleHelper(board, n, m, i, j - 1, c, t, d);
}
bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    // Write your code here.
    int **d = new int *[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = new int[m];
        for (int j = 0; j < m; j++)
            d[i][j] = 0;
    }

    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < m && l == 0; j++)
        {
            if (d[i][j] == 0)
                hasCycleHelper(board, n, m, i, j, board[i][j], 0, d);

            if (l > 0)
                break;
        }
    }
    if (l > 0)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}