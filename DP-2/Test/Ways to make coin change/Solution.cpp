#include <iostream>
#include <vector>
using namespace std;

int helper(int S[], int m, int n)
{
    int i, j, x, y;
    int table[n + 1][m];
    for (i = 0; i < m; i++)
        table[0][i] = 1;
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int countWaysToMakeChange1(int denominations[], int numDenominations, int value)
{

    return helper(denominations, numDenominations, value);
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange1(denominations, numDenominations, value);

    delete[] denominations;
}