#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    // Write your code here
    int minNumb = input[0], minIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] < minNumb)
        {
            minNumb = input[i];
            minIndex = i;
        }
    }
    return minIndex;
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
    int output = arrayRotateCheck(arr, n);
    cout << output << endl;
}