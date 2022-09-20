#include <iostream>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    // Write your code here
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {           
            if (arr[i] + arr[j] == num)
            {
                count++;
            }
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
    cout << pairSum(input, size, x) << endl;

    delete[] input;
}