/**
 *
 * Factorial works on LIFO (Last In First Out). it is called call stack.
 *
 **/

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int fact = factorial(n - 1);
    return n * fact;
}

int main()
{
    int n;
    cin >> n;
    int output = factorial(n);
    cout << output << endl;
}