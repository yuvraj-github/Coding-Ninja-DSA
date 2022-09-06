#include <iostream>
using namespace std;

int power(int x, int n)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    int powerOfX = 1;
    for (int i = 1; i <= n; i++)
    {
        powerOfX = powerOfX * x;
    }
    return powerOfX;
}

int main()
{
    int x, n;
    cin >> x >> n;
    int output = power(x, n);
    cout << output << endl;
}