/**
 * 
 * Sample Input 1 : 2 3 1
 * 
 * Sample Output 1: 6
 **/

#include <iostream>
using namespace std;

int sumOfElements = 0;
int sum(int input[], int n)
{
    if (n == 0)
    {
        return sumOfElements;
    }
    sumOfElements = sumOfElements + input[0];
    sum(input + 1, n - 1);
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
    int output = sum(arr, n);
    cout << output << endl;
}