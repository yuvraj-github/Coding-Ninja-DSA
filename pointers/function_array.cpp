#include <iostream>
using namespace std;

int sum(int a[], int size) {
    cout << sizeof(a) << endl;
    return 0;
}

int main()
{
    int a[10];
    cout << sizeof(a) << endl;
    cout << sum(a, 10) << endl;
}