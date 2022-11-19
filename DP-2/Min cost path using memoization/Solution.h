int minCostPathHelper(int **input, int m, int n, int **output, int i, int j)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    // proceed right.
    int x = minCostPathHelper(input, m, n, output, i, j + 1);

    // proceed down.
    int y = minCostPathHelper(input, m, n, output, i + 1, j);

    // proceed diagonal
    int z = minCostPathHelper(input, m, n, output, i + 1, j + 1);

    int ans = min(x, min(y, z)) + input[i][j];
    output[i][j] = ans;
    return output[i][j];
}

int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }  
    return minCostPathHelper(input, m, n, output, 0, 0);
}
