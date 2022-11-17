int countMinStepsHelper(int n, int *ans)
{
    // Base case
    if (n <= 1)
    {
        return 0;
    }

    // check if output already exists.

    if (ans[n] != -1)
    {
        return ans[n];
    }

    // calculate output    
    int x = countMinStepsHelper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = countMinStepsHelper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsHelper(n / 3, ans);
    }
    int output = min(x, min(y, z))+1;
    ans[n] = output;
    return ans[n];
}
int countStepsToOne(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <=n; i++)
    {
        ans[i] = -1;
    }
    return countMinStepsHelper(n, ans);
}