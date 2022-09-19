#include <iostream>
using namespace std;
void mergeArr(int *input, int si, int mid, int ei)
{
    int size = ei - si + 1;
    int *mergedArr = new int[size];
    int idx1 = si;
    int idx2 = mid + 1;
    int k = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (input[idx1] <= input[idx2])
        {
            mergedArr[k++] = input[idx1++];
        }
        else
        {
            mergedArr[k++] = input[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        mergedArr[k++] = input[idx1++];
    }
    while (idx2 <= ei)
    {
        mergedArr[k++] = input[idx2++];
    }
    for (int i = 0, j = si; i < k; i++, j++)
    {
        input[j] = mergedArr[i];
    }
    delete[] mergedArr;
}
void mergeSort(int *input, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort(input, si, mid);
    mergeSort(input, mid + 1, ei);
    mergeArr(input, si, mid, ei);
}
void intersection(int *arr1, int *arr2, int n, int m)
{
    // Write your code here
    int j = 0;
    int i = 0;
    while (i < n && j<m)
    {        
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] <<endl;
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int m, n;
    cin >> n;  
    cin >> m; 
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }    
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    mergeSort(arr1, 0, n - 1);
    mergeSort(arr2, 0, m - 1);
    intersection(arr1, arr2, n, m);
}