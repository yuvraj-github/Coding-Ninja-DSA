#include <iostream>
using namespace std;

bool checkNumber(int input[], int size, int x)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    if(size==0) {
        return false;
    }
    if(input[0] == x) {
        return true;
    }
    checkNumber(input+1, size-1, x);
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
    int x;
    cin >> x;
    bool output = checkNumber(arr, n, x);
    cout<<output<<endl;
}