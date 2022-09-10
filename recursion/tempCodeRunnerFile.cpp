#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    // Write your code here
    if (n > 0 || n <= 9)
    {
        return n;
    }
    if (n == 0)
    {
        return 0;
    }
    int sum = n % 10 + sumOfDigits(n / 10);
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int output = sumOfDigits(n);
    cout << output << endl;
}