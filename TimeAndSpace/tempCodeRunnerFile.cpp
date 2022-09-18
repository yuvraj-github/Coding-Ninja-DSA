#include <iostream>
using namespace std;

int findUnique(int *arr, int n)
{
    // Write your code here
    int output = arr[0];
    for (int i = 1; i < n; i++)
    {
        output = output ^ arr[i];
    }
    return output;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    int output = findUnique(arr, n);
    cout << output << endl;
}