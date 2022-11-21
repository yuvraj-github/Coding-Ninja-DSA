#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//using dp

int maxMoneyLootedDp(int *arr, int n) {
    int dp[n];
    dp[0] = arr[0]; 
    dp[1]=max(arr[0],arr[1]);  
    for(int i=2; i<n; i++) {
        int incl = dp[i-2]+arr[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);        
    }    
    return dp[n-1];
}

// using memoization

int maxMoneyLootedMemHelper(int *arr, int n, int *output)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    if (output[n] != -1)
    {
        return output[n];
    }
    int incl = maxMoneyLootedMemHelper(arr, n - 2, output) + arr[n];
    int excl = maxMoneyLootedMemHelper(arr, n - 1, output) + 0;
    int ans = max(incl, excl);
    output[n] = ans;
    return output[n];
}
int maxMoneyLootedMem(int *arr, int n)
{
    int *output = new int[n+1];
    for (int i = 0; i <=n; i++)
    {
        output[i] = -1;
    }
    return maxMoneyLootedMemHelper(arr, n, output);
}
// Brut force.
int maxMoneyLooted(int *arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    int incl = maxMoneyLooted(arr, n - 2) + arr[n];
    int excl = maxMoneyLooted(arr, n - 1) + 0;
    return max(incl, excl);
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

    // cout << maxMoneyLooted(arr, n);
    //cout << maxMoneyLootedMem(arr, n);
    cout << maxMoneyLootedDp(arr, n);

    delete[] arr;
}