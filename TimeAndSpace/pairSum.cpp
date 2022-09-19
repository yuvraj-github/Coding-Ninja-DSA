#include <iostream>
using namespace std;

void mergeArr(int *arr, int si, int mid, int ei)
{
    int size = ei - si + 1;
    int *mergedArr = new int[size];
    int idx1 = si;
    int idx2 = mid + 1;
    int k = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            mergedArr[k++] = arr[idx1++];
        }
        else
        {
            mergedArr[k++] = arr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        mergedArr[k++] = arr[idx1++];
    }
    while (idx2 <= ei)
    {
        mergedArr[k++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < k; i++, j++)
    {
        arr[j] = mergedArr[i];
    }
    delete[] mergedArr;
}
void mergeSort(int *arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    mergeArr(arr, si, mid, ei);
}
int pairSum(int *arr, int n, int num)
{
    // Write your code here
    mergeSort(arr, 0, n - 1);
    int i = 0;
    int j = n;
    int count = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == num)
        {
            count++;
            if (arr[i] == arr[i + 1])
            {
                i++;
                continue;
            }
            else if (arr[j] == arr[j - 1])
            {
                count++;
                j--;
                continue;
            }
            else
            {
                i++;
                j--;
            }
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            j--;
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
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    cout << pairSum(input, size, x) << endl;

    delete[] input;
}