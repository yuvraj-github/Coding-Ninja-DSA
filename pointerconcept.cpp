#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    cout<< i <<endl;
    cout << sizeof(p) << endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    return 0;
}