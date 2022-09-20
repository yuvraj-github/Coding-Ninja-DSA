#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int tripletSum(int *arr, int n, int num)
{
    // Write your code here
    sort(arr, arr + n);
    int count = 0;
    sort(arr, arr + n);
    int a, b, c;
    int low, high;

    for (int i = 0; i < n; i++)
    {
        low = i + 1;
        high = n - 1;
        while (low < high)
        {
            a = arr[i];
            b = arr[low];
            c = arr[high];

            if (a + b + c == num)
            {
                int p = low;
                while (p < high && a + arr[p] + c == num)
                {
                    count++;
                    p++;
                }
                high--;
            }
            else if (a + b + c < num)
                low++;

            else
                high--;
        }
    }
    return count;
}
int main()
{
    int size;
    int x;

    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    cin >> x;
    cout << tripletSum(input, size, x) << endl;

    delete[] input;
}