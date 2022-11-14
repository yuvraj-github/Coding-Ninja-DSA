#include <bits/stdc++.h>
using namespace std;
#include <vector>
bool isSafe(int x, int y, int n, vector<vector<int>> &maize, vector<vector<int>> &output)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && maize[x][y] == 1 && output[x][y] == 0)
    {
        return true;
    }
    return false;
}
void printOutput(int x, int y, int n, vector<vector<int>> &maize, vector<vector<int>> &output)
{
    if (x == n - 1 && y == n - 1)
    {
        output[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << output[i][j] << " ";
            }
        }
        cout << endl;
    }
    if (isSafe(x - 1, y, n, maize, output))
    {
        output[x][y] = 1;
        printOutput(x - 1, y, n, maize, output);
    }
    if (isSafe(x + 1, y, n, maize, output))
    {
        output[x][y] = 1;
        printOutput(x + 1, y, n, maize, output);
    }
    if (isSafe(x, y - 1, n, maize, output))
    {
        output[x][y] = 1;
        printOutput(x, y - 1, n, maize, output);
    }
    if (isSafe(x, y + 1, n, maize, output))
    {
        output[x][y] = 1;
        printOutput(x, y + 1, n, maize, output);
    }
    output[x][y] = 0;
}
void ratInMaize(vector<vector<int>> &maize, int n)
{
    vector<vector<int>> output(n, vector<int>(n, 0));
    if (maize[0][0] == 0)
    {
        return;
    }
    printOutput(0, 0, n, maize, output);
}
int main()
{
    // Write your code here
    int n;
    cin >> n;
    vector<vector<int>> maize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maize[i][j];
        }
    }
    ratInMaize(maize, n);
    return 0;
}
