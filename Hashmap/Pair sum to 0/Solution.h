#include <unordered_map>
int pairSum(int *arr, int n)
{
    // Write your code here
    if (arr == nullptr || n <= 0)
        return -1;
    unordered_map<int, int> myMap;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int inverse = -arr[i];
        if (myMap.count(inverse))
        {
            int count = myMap[inverse]; 
            if (inverse > 0)
                inverse *= -1; 
            for (int j = 0; j < count; j++)
                sum++;
        }
        myMap[arr[i]]++;
    }
    return sum;
}