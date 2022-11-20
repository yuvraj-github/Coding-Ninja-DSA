#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Using memoization
int knapsackHelper(int *weights, int *values, int n, int maxWeight, int dp[101][21])
{
    if (n == 0 || maxWeight == 0)
        return 0;
    if (dp[maxWeight][n] != -1)
        return dp[maxWeight][n];
    if (weights[0] > maxWeight)
        return dp[maxWeight][n] = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, dp);
    else
    {
        int x = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp) + values[0];
        int y = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, dp);
        int ans = max(x, y);
        dp[maxWeight][n] = ans;
        return ans;
    }
}
*/

// solved solution using space complexity O(N*W)
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Write your code here
    int dp[n + 1][maxWeight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (weight[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
        }
    }
    return dp[n][maxWeight];
}
int main()
{
    int weights[] = {10, 5, 8, 1, 10, 7};
    int values[] = {8, 4, 8, 6, 5, 1};
    int W = 13;
    cout << knapsack(weights, values, 4, W) << endl;
}