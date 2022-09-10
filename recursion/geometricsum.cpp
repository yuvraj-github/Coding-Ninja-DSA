/** 1+1/2+1/4+ 1/8.... **/

/**
 * 
 * Sample Input 1 : 1+1/2+1/4+1/8
 * 
 * Sample Output 1: 1.875
 **/

#include <iostream>
#include <math.h>
using namespace std;

double geometricSum(int k)
{
    // Write your code here
    if (k == 0)
    {
        return 1;
    }
    double sum = 1 / (double)pow(2, k) + geometricSum(k - 1);
    return sum;
}

int main()
{
    int n;
    cin >> n;
    double output = geometricSum(n);
    cout << output << endl;
}