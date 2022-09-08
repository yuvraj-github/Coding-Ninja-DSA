#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    if (size == 0)
    {
        return -1;
    }
    if (input[size] == x)
    {
        return size;
    }
    lastIndex(input, size - 1, x);
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    int output = lastIndex(arr, n, x);
    cout << output << endl;
}