#include <bits/stdc++.h>
using namespace std;

long countPossibleWaysHelper(int n, long *ans)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int x = countPossibleWaysHelper(n - 1, ans);
    int y = countPossibleWaysHelper(n - 2, ans);
    int z = countPossibleWaysHelper(n - 3, ans);
    ans[n] = x + y + z;
    return ans[n];
}
long countPossibleWays(int n)
{
    long *ans = new long[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return countPossibleWaysHelper(n, ans);
}
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countPossibleWays(n) << endl;
    }

    return 0;
}