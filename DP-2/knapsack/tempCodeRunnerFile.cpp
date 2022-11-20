#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsackHelper(int *weights, int *values, int n, int maxWeight, int dp[101][21])
{
    if (n == 0 || maxWeight == 0)
        return 0;
    if (dp[maxWeight][n] != -1)
        return dp[maxWeight][n];
    if (weights[0] > maxWeight)
        return dp[maxWeight][n] = dp[maxWeight][n] = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, dp);

    else
        return dp[maxWeight][n] = dp[maxWeight][n] = max(values[0] + knapsackHelper(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp),
                                                         knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, dp));
}
int knapsack(int *weight, int *values, int n, int maxWeight)
{
    int output[101][21];
    memset(output, -1, sizeof(output));
    return knapsackHelper(weight, values, n, maxWeight, output);
}
int main()
{
    int weights[] = {4, 1, 4, 5};
    int values[] = {4, 5, 10, 1};
    int W = 5;
    cout << knapsack(weights, values, 4, W) << endl;
}