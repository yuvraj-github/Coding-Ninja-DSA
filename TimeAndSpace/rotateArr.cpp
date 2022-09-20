#include <iostream>
using namespace std;

void reverse(int *input, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int temp = input[si];
    input[si] = input[ei];
    input[ei] = temp;
    reverse(input, si + 1, ei - 1);
}
void rotate(int *input, int d, int n)
{
    // Write your code here
    reverse(input, 0, n - 1);
    reverse(input, 0, n-d-1);
    reverse(input, n-d, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin>>d;
    rotate(arr, d, n);
}