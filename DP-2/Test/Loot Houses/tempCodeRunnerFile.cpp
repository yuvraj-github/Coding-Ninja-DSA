#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}