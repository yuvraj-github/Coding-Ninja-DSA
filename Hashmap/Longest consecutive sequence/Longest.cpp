#include <iostream>
#include <vector>
using namespace std;

#include "solution.h"

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
