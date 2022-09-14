/**
 *
 * It is based on pivot and partition method.
 *
 * TIme complexity: worst case ----  O(n expo 2) i.e; n square.
 *                  best case --- O(nlogn)
 *
 **/

#include <iostream>
using namespace std;

void swap(int input[], int i, int j)
{
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

int partition(int input[], int si, int ei)
{
    int pivot = input[ei];
    int i = si - 1;
    for (int j = si; j < ei; j++)
    {
        if (input[j] < pivot)
        {
            i++;
            swap(input, i, j);
        }
    }
    swap(input, i+1, ei);
    return i+1;
}

void quickSort(int input[], int start, int end)
{
    // your code goes here
    if (start >= end)
    {
        return;
    }
    int pivIndex = partition(input, start, end);
    quickSort(input, start, pivIndex - 1);
    quickSort(input, pivIndex + 1, end);
}
void quickSort(int input[], int size)
{    
    if (size <= 1)
    {
        return;
    }
    quickSort(input, 0, size - 1);
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
    quickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}