#include <iostream>
using namespace std;
int a;// global variable. But we never ever use this because it is not a goog practice.
void g()
{
    a++;
    cout << a << endl;
}
void f()
{
    cout << a << endl;
    a++;
    g();
}
int main()
{
    a = 10;
    f();
    cout << a << endl;
}