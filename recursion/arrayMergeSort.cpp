/** 
 * It is based on divide and conquer method.
 * 
 * Time complexity: O(nlogn). 
 * 
 **/

#include <iostream>
using namespace std;

void performMerged(int input[], int si, int mid, int ei)
{
    int size = ei - si + 1;
    int *mergedArr = new int[size];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (input[idx1] <= input[idx2])
        {
            mergedArr[x++] = input[idx1++];
        }
        else
        {
            mergedArr[x++] = input[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        mergedArr[x++] = input[idx1++];
    }
    while (idx2 <= ei)
    {
        mergedArr[x++] = input[idx2++];
    }
    for (int i = 0, j = si; i < size; i++, j++)
    {
        input[j] = mergedArr[i];
    }
    delete[] mergedArr;
}

void performDivide(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    performDivide(input, si, mid);
    performDivide(input, mid + 1, ei);
    performMerged(input, si, mid, ei);
}
void mergeSort(int input[], int size)
{
    if (size == 1)
    {
        return;
    }
    int si = 0;
    int ei = size - 1;
    performDivide(input, si, ei);
}
int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    mergeSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}