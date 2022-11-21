#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// using dp

int solveByDp(int *arr, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int incl = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                incl = 1 + dp[curr+1][curr+1];
            }
            int excl = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(incl, excl);
        }
    }
    return dp[0][0];
}

// using memoization

int solveByMemoizationHelper(int *arr, int n, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == n)
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    int incl = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        incl = 1 + solveByMemoizationHelper(arr, n, curr + 1, curr, dp);
    }
    int excl = 0 + solveByMemoizationHelper(arr, n, curr + 1, prev, dp);
    dp[curr][prev + 1] = max(incl, excl);
    return dp[curr][prev + 1];
}
int solveByMemoization(int *arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveByMemoizationHelper(arr, n, 0, -1, dp);
}

// using recursion(brute force)

int solveByrecursion(int *arr, int n, int curr, int prev)
{
    if (curr == n)
    {
        return 0;
    }
    int incl = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        incl = 1 + solveByrecursion(arr, n, curr + 1, curr);
    }
    int excl = 0 + solveByrecursion(arr, n, curr + 1, prev);
    return max(incl, excl);
}
int longestIncreasingSubsequence(int *arr, int n)
{
    // Write your code here
    return solveByrecursion(arr, n, 0, -1);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << longestIncreasingSubsequence(arr, n);
    // cout << solveByMemoization(arr, n);
    cout << solveByDp(arr, n);
}