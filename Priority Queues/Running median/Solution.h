#include <queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max.push(arr[i]);
        } // push is any of the heap  //max or min

        else
        {
            if (arr[i] < max.top())
                max.push(arr[i]);
            else
                min.push(arr[i]);
        }
        // keeping in check that both heap are almost of same size
        if (int(max.size() - min.size()) > 1)
        {
            int x = max.top();
            max.pop();
            min.push(x);
        }
        else if (int(min.size() - max.size()) > 1)
        {
            int x = min.top();
            min.pop();
            max.push(x);
        }

        int c = max.size() + min.size(); // count

        // checking size of list to find median
        if (c % 2 == 0)
            cout << (max.top() + min.top()) / 2 << ' ';
        else
        {
            if (max.size() > min.size())
                cout << max.top() << ' ';
            else
                cout << min.top() << ' ';
        }
    }
}