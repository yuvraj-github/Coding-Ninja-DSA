#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "Solution.h"

int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
   cout<<minCostPath(input, m, n);
}