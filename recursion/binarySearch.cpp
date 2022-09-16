#include <iostream>
using namespace std;

int performBinarySearch(int input[], int si, int ei, int element)
{
    if (si >= ei)
    {
        return -1;
    }
    int mid = si + (ei-si) / 2;
    if (element < input[mid])
    {
        performBinarySearch(input, si, mid, element);
    }
    else if (element > input[mid])
    {
        performBinarySearch(input, mid+1, ei, element);
    }
    else
    {
        return mid;
    }
}

int binarySearch(int input[], int size, int element)
{
    // Write your code here
    if (size <= 0)
    {
        return -1;
    }
    int output = performBinarySearch(input, 0, size-1, element);
    return output;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int output = binarySearch(arr, n, x);
    cout << output << endl;
}