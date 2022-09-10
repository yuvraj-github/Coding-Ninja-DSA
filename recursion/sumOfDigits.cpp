/**
 * 
 * Sample Input 1 : 123
 * 
 * Sample Output 1: 5
 **/

#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    // Write your code here   
    if (n == 0)
    {
        return 0;
    }
    return n%10+sumOfDigits(n / 10);    
}

int main()
{
    int n;
    cin >> n;
    int output = sumOfDigits(n);
    cout << output << endl;
}