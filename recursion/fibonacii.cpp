#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int smallOutput1 = fib(n - 1);
    int smallOutput2 = fib(n - 2);
    return smallOutput1 + smallOutput2;
}

int main()
{
    int n;
    cin >> n;
    cout << 0 << ends;
    for (int i = 1; i <= n; i++)
    {
        int printFib = fib(i);
        cout << printFib << ends;
    }
}