#include <iostream>
using namespace std;

#include "Solution.h"

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}