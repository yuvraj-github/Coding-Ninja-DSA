#include <algorithm>
int binarySearch(int arr[], int X, int low, int N)
{
    int high = N - 1;
    int ans = N;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= X)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    int count = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
    {
        int X = binarySearch(arr, arr[i] + k, i + 1, n);
        if (X != n)
        {
            int Y = binarySearch(arr, arr[i] + k + 1, i + 1, n);
            count += Y - X;
        }
    }

    return count;
}