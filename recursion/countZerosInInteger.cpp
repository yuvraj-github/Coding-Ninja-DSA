#include <iostream>
using namespace std;

int countZeros(int n)
{
    // Write your code here
    if (n <= 9)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int smallOutput = countZeros(n / 10);
    if (n % 10 == 0)
    {
        smallOutput++;
    }
    return smallOutput;
}

int main()
{
    int n;
    cin >> n;
    int output = countZeros(n);
    cout << output << endl;
}