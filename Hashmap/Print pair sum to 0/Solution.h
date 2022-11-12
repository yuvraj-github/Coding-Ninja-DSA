#include <unordered_map>
void pairSum(int *arr, int n)
{
    // Write your code here
    if (n <= 0)
        return;
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        int inverse = -arr[i];
        if (myMap.count(inverse))
        {
            int count = myMap[inverse]; 
            if (inverse > 0)
                inverse *= -1; 
            for (int j = 0; j < count; j++)
                cout << inverse << ' ' << -inverse <<endl;
        }
        myMap[arr[i]]++;
    }   
}