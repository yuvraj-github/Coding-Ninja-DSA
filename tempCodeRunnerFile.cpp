#include <iostream>
using namespace std;

int main()
{
    int a = 50;
    int *ptr = &a;
    // cout << (*ptr)++ << " " ;
    (*ptr)++;
    cout << a << endl;
}