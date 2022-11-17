int countMinStepsToOne(int n)
{
    // Write your code here
    //  Base case
    if (n <= 1)
    {
        return 0;
    }

    // Recursive call
    int x = countMinStepsToOne(n - 1);

    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = countMinStepsToOne(n / 2);
    }

    if (n % 3 == 0)
    {
        z = countMinStepsToOne(n / 3);
    }

    // Calculate final output
    int ans = min(x, min(y, z)) + 1;

    return ans;
}