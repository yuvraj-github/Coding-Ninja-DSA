/**
 *
 * Sample Input 1 : 2
 *
 * Sample Output 1: a b
 *                  a c
 *                  b c
 *
 * Sample Input 1 : 3
 *
 * Sample Output 1: a c
 *                  a b
 *                  c b
 *                  a c
 *                  b a
 *                  b c
 *                  a c
 **/

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    // Write your code here
    if (n == 1)
    {
        cout << source << ends << destination<<endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << source << ends << destination<<endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;
    cin >> n;    
    towerOfHanoi(n, 'a', 'b', 'c');
}