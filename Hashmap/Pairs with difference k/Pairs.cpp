#include <iostream>
using namespace std;

#include "Solution.h"

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}